#include "Media.h"

#if defined(_USING_HID)

//================================================================================
//================================================================================
//  Media

static const uint8_t _hidReportDescriptor[] PROGMEM = {

  //  Remote
    0x05, 0x0c,                    // Usage Page (Consumer Devices)
    0x09, 0x01,                    // Usage (Consumer Control)
    0xa1, 0x01,                    // Collection (Application)
    0x85, 0x04,                    // REPORT_ID (4)
    0x15, 0x00,                    // Logical Minimum (0)
    0x25, 0x01,                    // Logical Maximum (1)
    0x09, 0xe9,                    // Usage (Volume Up)
    0x09, 0xea,                    // Usage (Volume Down)
    0x75, 0x01,                    // Report Size (1)
    0x95, 0x02,                    // Report Count (2)
    0x81, 0x06,                    // Input (Data, Variable, Relative)

    0x09, 0xe2,                    // Usage (Mute)
    0x95, 0x01,                    // Report Count (1)
    0x81, 0x06,                    // Input (Data, Variable, Relative)

    0x09, 0xb0,                    // Usage (Play)
    0x95, 0x01,                    // Report Count (1)
    0x81, 0x06,                    // Input (Data, Variable, Relative)

    0x09, 0xb1,                    // Usage (Pause)
    0x95, 0x01,                    // Report Count (1)
    0x81, 0x06,                    // Input (Data, Variable, Relative)

    0x09, 0xb7,                    // Usage (Stop)
    0x95, 0x01,                    // Report Count (1)
    0x81, 0x06,                    // Input (Data, Variable, Relative)

    0x09, 0xb5,                    // Usage (Next)
    0x95, 0x01,                    // Report Count (1)
    0x81, 0x06,                    // Input (Data, Variable, Relative)

    0x09, 0xb6,                    // Usage (Previous)
    0x95, 0x01,                    // Report Count (1)
    0x81, 0x06,                    // Input (Data, Variable, Relative)

    0x09, 0xb3,                    // Usage (Fast Forward)
    0x95, 0x01,                    // Report Count (1)
    0x81, 0x06,                    // Input (Data, Variable, Relative)

    0x09, 0xb4,                    // Usage (Rewind)
    0x95, 0x01,                    // Report Count (1)
    0x81, 0x06,                    // Input (Data, Variable, Relative)

    0x95, 0x06,                    // Report Count (6) Number of bits remaining in byte
    0x81, 0x07,                    // Input (Constant, Variable, Relative)
    0xc0                           // End Collection
};

Media_::Media_(void)
{
  static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
  HID().AppendDescriptor(&node);
}

void Media_::send(uint16_t cmd) {
  u8 m[2];
  if (cmd <= 128) {
    m[0] = cmd;
    m[1] = 0;
  }
  else {
    m[0] = 0;
    m[1] = cmd >> 8;
  }
  sendReport(4,m,2);
}

void Media_::increase(void)
{
  send(MEDIA_VOL_UP);
}

void Media_::decrease(void)
{
  send(MEDIA_VOL_DOWN);
}

void Media_::mute(void)
{
  send(MEDIA_MUTE);
}

void Media_::play(void)
{
  send(MEDIA_PLAY);
}

void Media_::pause(void)
{
  send(MEDIA_PAUSE);
}

void Media_::stop(void)
{
  send(MEDIA_STOP);
}

void Media_::next(void)
{
  send(MEDIA_NEXT);
}

void Media_::previous(void)
{
  send(MEDIA_PREV);
}

void Media_::forward(void)
{
  send(MEDIA_FFD);
}

void Media_::rewind(void)
{
  send(MEDIA_RWD);
}

void Media_::clear(void)
{
  send(0);
}

void Media_::sendReport(uint8_t id, const void* data, int len)
{
  HID().SendReport(id, data, len);
}

Media_ Media;

#endif
