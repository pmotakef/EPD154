/**
 *  @filename   :   epd1in54b.cpp
 *  @brief      :   Implements for e-paper library
 *  @author     :   Yehui from Waveshare
 *
 *  Copyright (C) Waveshare     August 10 2017
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documnetation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to  whom the Software is
 * furished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdlib.h>
#include "EPD.h"

EPD::~EPD() {
};

EPD::EPD() {
    reset_pin = RST_PIN;
    dc_pin = DC_PIN;
    cs_pin = CS_PIN;
    busy_pin = BUSY_PIN;
    width = EPD_WIDTH;
    height = EPD_HEIGHT;
};

int EPD::Init(void) {
    /* this calls the peripheral hardware interface, see epdif */
    if (IfInit() != 0) {
        return -1;
    }
    /* EPD hardware init start */
    Reset();
    SendCommand(POWER_SETTING);
    SendData(0x07);
    SendData(0x00);
    SendData(0x08);
    SendData(0x00);
    SendCommand(BOOSTER_SOFT_START);
    SendData(0x07);
    SendData(0x07);
    SendData(0x07);
    SendCommand(POWER_ON);

    WaitUntilIdle();

    SendCommand(PANEL_SETTING);
    SendData(0xcf);
    SendCommand(VCOM_AND_DATA_INTERVAL_SETTING);
    SendData(0x17);
    SendCommand(PLL_CONTROL);
    SendData(0x39);
    SendCommand(TCON_RESOLUTION);
    SendData(0xC8);
    SendData(0x00);
    SendData(0xC8);
    SendCommand(VCM_DC_SETTING_REGISTER);
    SendData(0x0E);

    SetLutBw();
    SetLutRed();
    /* EPD hardware init end */

    return 0;
}

/**
 *  @brief: basic function for sending commands
 */
void EPD::SendCommand(unsigned char command) {
    DigitalWrite(dc_pin, LOW);
    SpiTransfer(command);
}

/**
 *  @brief: basic function for sending data
 */
void EPD::SendData(unsigned char data) {
    DigitalWrite(dc_pin, HIGH);
    SpiTransfer(data);
}

/**
 *  @brief: Wait until the busy_pin goes HIGH
 */
void EPD::WaitUntilIdle(void) {
    while(DigitalRead(busy_pin) == 0) {      //0: busy, 1: idle
        DelayMs(100);
    }      
}

/**
 *  @brief: module reset.
 *          often used to awaken the module in deep sleep,
 *          see Epd::Sleep();
 */
void EPD::Reset(void) {
    DigitalWrite(reset_pin, LOW);                //module reset    
    DelayMs(200);
    DigitalWrite(reset_pin, HIGH);
    DelayMs(200);    
}

/**
 *  @brief: set the look-up tables
 */
void EPD::SetLutBw(void) {
    unsigned int count;     
    SendCommand(0x20);         //g vcom
    for(count = 0; count < 15; count++) {
        SendData(lut_vcom0[count]);
    } 
    SendCommand(0x21);        //g ww --
    for(count = 0; count < 15; count++) {
        SendData(lut_w[count]);
    } 
    SendCommand(0x22);         //g bw r
    for(count = 0; count < 15; count++) {
        SendData(lut_b[count]);
    } 
    SendCommand(0x23);         //g wb w
    for(count = 0; count < 15; count++) {
        SendData(lut_g1[count]);
    } 
    SendCommand(0x24);         //g bb b
    for(count = 0; count < 15; count++) {
        SendData(lut_g2[count]);
    } 
}

void EPD::SetLutRed(void) {
    unsigned int count;     
    SendCommand(0x25);
    for(count = 0; count < 15; count++) {
        SendData(lut_vcom1[count]);
    } 
    SendCommand(0x26);
    for(count = 0; count < 15; count++) {
        SendData(lut_red0[count]);
    } 
    SendCommand(0x27);
    for(count = 0; count < 15; count++) {
        SendData(lut_red1[count]);
    } 
}

void EPD::DisplayFrame(const unsigned char* frame_buffer_black, const unsigned char* frame_buffer_red) {
    unsigned char temp;
    if (frame_buffer_black != NULL) {
        SendCommand(DATA_START_TRANSMISSION_1);
        DelayMs(2);
        for (int i = 0; i < this->width * this->height / 8; i++) {
            temp = 0x00;
            for (int bit = 0; bit < 4; bit++) {
                if ((pgm_read_byte(&frame_buffer_black[i]) & (0x80 >> bit)) != 0) {
                    temp |= 0xC0 >> (bit * 2);
                }
            }
            SendData(temp);
            temp = 0x00;
            for (int bit = 4; bit < 8; bit++) {
                if ((pgm_read_byte(&frame_buffer_black[i]) & (0x80 >> bit)) != 0) {
                    temp |= 0xC0 >> ((bit - 4) * 2);
                }
            }
            SendData(temp);
        }
        DelayMs(2);
    }
    if (frame_buffer_red != NULL) {
        SendCommand(DATA_START_TRANSMISSION_2);
        DelayMs(2);
        for (int i = 0; i < this->width * this->height / 8; i++) {
            SendData(pgm_read_byte(&frame_buffer_red[i]));
        }
        DelayMs(2);
    }
    SendCommand(DISPLAY_REFRESH);
    WaitUntilIdle();
}

void EPD::Test(void) {
    SendCommand(DATA_START_TRANSMISSION_1);
    DelayMs(2);
    for (int i = 0; i < this->width * this->height / 8; i++) {
        unsigned char temp = 0xFF;
        unsigned char col = 0x00;
        if (i % 10 == 0) {
            col = 0X00;
        }
        // for (int bit = 0; bit < 4; bit++) {
        //     if ((pgm_read_byte(col) & (0x80 >> bit)) != 0) {
        //         temp |= 0xC0 >> (bit * 2);
        //     }
        // }
        SendData(col);
        // for (int bit = 4; bit < 8; bit++) {
        //     if ((pgm_read_byte(col) & (0x80 >> bit)) != 0) {
        //         temp |= 0xC0 >> ((bit - 4) * 2);
        //     }
        // }
        SendData(temp);
    }
    DelayMs(2);
    SendCommand(DATA_START_TRANSMISSION_2);
    DelayMs(2);
    unsigned char temp = 0xFF;
    for (int i = 0; i < this->width * this->height / 8; i++) {
        SendData(temp);
    }
    DelayMs(2);
    SendCommand(DISPLAY_REFRESH);
    WaitUntilIdle();
}

void EPD::Clear(void) {
    unsigned char col = 0xFF;
    SendCommand(DATA_START_TRANSMISSION_1);
    DelayMs(2);
    for (int i = 0; i < this->width * this->height / 4; i++) {
        SendData(col);
    }
    DelayMs(2);
    SendCommand(DATA_START_TRANSMISSION_2);
    DelayMs(2);
    for (int i = 0; i < this->width * this->height / 8; i++) {
        SendData(col);
    }
    DelayMs(2);
    SendCommand(DISPLAY_REFRESH);
    WaitUntilIdle();
}

void EPD::DisplayPartialTextFrame(char* buffer, sFONT* font, int num_rows, bool bw_color, bool char_as_ref) {
        int num_cols = int(width / font->Width);
        int dots_per_byte = 8;
        if (bw_color) {
            dots_per_byte = 4;
        }
        int offset_x = 200 - (num_cols * font->Width);

        for (int row=0; row < num_rows; row++) {
            for (int h=0; h < font->Height; h++) {
                for (int j=0; j < int(offset_x / dots_per_byte); j++) {
                    SendData((unsigned char)0xFF);
                }
                for (int col=0; col < num_cols; col++) {
                    int idx = row * num_cols + col;
                    DrawCharLine(h, buffer[idx], font, bw_color, char_as_ref);
                }
            }
        }
}

void EPD::AddEmptyRowsToPartialDisplay(int num_rows, bool bw_buffer, bool colored) {
    int dots_per_byte = 8;
    if (bw_buffer) {
        dots_per_byte = 4;
    }
    unsigned char col = 0xFF;
    if (colored) {
        col = 0x00;
    }
    for (int j=0; j < num_rows; j++) {
        for (int z=0; z < width / dots_per_byte; z++){
            SendData(col);
        }
    }
}

void EPD::RefreshPartialDisplay(void){
    SendCommand(DISPLAY_REFRESH);
    WaitUntilIdle();
}

void EPD::PreparePartialDisplay(bool bw_color) {
    unsigned char command = DATA_START_TRANSMISSION_2;
    if (bw_color) {
        command = DATA_START_TRANSMISSION_1;
    }
    SendCommand(command);
    DelayMs(2);
}

void EPD::FinishPartialDisplay(void) {
    DelayMs(2);
}

void EPD::DisplayTextFrame(char* black_buffer, char* red_buffer, sFONT* font){
    int num_cols = int(width / font->Width);
    int num_rows = int(height / font->Height);
    int offset_x = 200 - (num_cols * font->Width);
    int offset_y = 200 - (num_rows * font->Height);
    // Black and White part
    if (black_buffer != NULL) {
        SendCommand(DATA_START_TRANSMISSION_1);
        DelayMs(2);

        for (int row=0; row < num_rows; row++) {
            for (int h=0; h < font->Height; h++) {
                for (int j=0; j < int(offset_x / 4); j++) {
                    SendData((unsigned char)0xFF);
                }
                for (int col=0; col < num_cols; col++) {
                    int idx = row * num_cols + col;
                    DrawCharLine(h, black_buffer[idx], font, true, false);
                }
            }
        }
        for (int j=0; j < offset_y; j++) {
            for (int z=0; z < width / 4; z++){
                SendData((unsigned char)0xFF);
            }
        }
        DelayMs(2);
    }

    // Red and White part
    if (red_buffer != NULL) {
        SendCommand(DATA_START_TRANSMISSION_2);
        DelayMs(2);
        for (int row=0; row < num_rows; row++) {
            for (int h=0; h < font->Height; h++) {
                for (int j=0; j < int(offset_x / 8); j++) {
                    SendData((unsigned char)0xFF);
                }
                for (int col=0; col < num_cols; col++) {
                    int idx = row * num_cols + col;
                    DrawCharLine(h, red_buffer[idx], font, false, false);
                }
            }
        }
        for (int j=0; j < offset_y; j++) {
            for (int z=0; z < width / 8; z++){
                SendData((unsigned char)0xFF);
            }
        }
        DelayMs(2);
    }
    SendCommand(DISPLAY_REFRESH);
    WaitUntilIdle();

}

void EPD::DrawCharLine(int line, char ascii_char, sFONT* font, bool bw_color, bool ascii_as_ref) {
    unsigned int char_offset;
    if (ascii_as_ref) {
        char_offset = (ascii_char) * font->Height * (font->Width / 8);
    }
    else
    {
        char_offset = (ascii_char - ' ') * font->Height * (font->Width / 8);
    }
    unsigned int line_offset = (font->Width / 8) * line;
    const unsigned char* ptr = &font->table[char_offset + line_offset];

    for (int i = 0; i < font->Width / 8; i++) {
        unsigned char val = ~pgm_read_byte(ptr);
        if (bw_color){
            SendBWData(val);
        }
        else {
            SendRedData(val);
        }
        ptr++;
    }
}

void EPD::SendBWData(unsigned char data) {
    unsigned char temp = 0x00;
    for (int bit = 0; bit < 4; bit++) {
        if ((data & (0x80 >> bit)) != 0) {
            temp |= 0xC0 >> (bit * 2);
        }
    }
    SendData(temp);
    temp = 0x00;
    for (int bit = 4; bit < 8; bit++) {
        if ((data & (0x80 >> bit)) != 0) {
            temp |= 0xC0 >> ((bit - 4) * 2);
        }
    }
    SendData(temp);
}

void EPD::SendRedData(unsigned char data) {
    SendData(data);
}



/**
 *  @brief: After this command is transmitted, the chip would enter the 
 *          deep-sleep mode to save power. 
 *          The deep sleep mode would return to standby by hardware reset. 
 *          The only one parameter is a check code, the command would be
 *          executed if check code = 0xA5. 
 *          You can use Epd::Init() to awaken
 */
void EPD::Sleep() {
    SendCommand(VCOM_AND_DATA_INTERVAL_SETTING);
    SendData(0x17);
    SendCommand(VCM_DC_SETTING_REGISTER);         //to solve Vcom drop
    SendData(0x00);
    SendCommand(POWER_SETTING);         //power setting
    SendData(0x02);        //gate switch to external
    SendData(0x00);
    SendData(0x00);
    SendData(0x00);
    WaitUntilIdle();
    SendCommand(POWER_OFF);         //power off
}

const unsigned char lut_vcom0[] =
{
    0x0E, 0x14, 0x01, 0x0A, 0x06, 0x04, 0x0A, 0x0A,
    0x0F, 0x03, 0x03, 0x0C, 0x06, 0x0A, 0x00
};

const unsigned char lut_w[] =
{
    0x0E, 0x14, 0x01, 0x0A, 0x46, 0x04, 0x8A, 0x4A,
    0x0F, 0x83, 0x43, 0x0C, 0x86, 0x0A, 0x04
};

const unsigned char lut_b[] = 
{
    0x0E, 0x14, 0x01, 0x8A, 0x06, 0x04, 0x8A, 0x4A,
    0x0F, 0x83, 0x43, 0x0C, 0x06, 0x4A, 0x04
};

const unsigned char lut_g1[] = 
{
    0x8E, 0x94, 0x01, 0x8A, 0x06, 0x04, 0x8A, 0x4A,
    0x0F, 0x83, 0x43, 0x0C, 0x06, 0x0A, 0x04
};

const unsigned char lut_g2[] = 
{
    0x8E, 0x94, 0x01, 0x8A, 0x06, 0x04, 0x8A, 0x4A,
    0x0F, 0x83, 0x43, 0x0C, 0x06, 0x0A, 0x04
};

const unsigned char lut_vcom1[] = 
{
    0x03, 0x1D, 0x01, 0x01, 0x08, 0x23, 0x37, 0x37,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char lut_red0[] = 
{
    0x83, 0x5D, 0x01, 0x81, 0x48, 0x23, 0x77, 0x77,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char lut_red1[] = 
{
    0x03, 0x1D, 0x01, 0x01, 0x08, 0x23, 0x37, 0x37,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/* END OF FILE */


