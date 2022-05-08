package com.jkqj.magick.image;

public interface ChannelType {
    int UndefinedChannel = 0x0000;
    int RedChannel = 0x0001;
    int GrayChannel = 0x0001;
    int CyanChannel = 0x0001;
    int LChannel = 0x0001;
    int GreenChannel = 0x0002;
    int MagentaChannel = 0x0002;
    int aChannel = 0x0002;
    int BlueChannel = 0x0004;
    int bChannel = 0x0002;
    int YellowChannel = 0x0004;
    int BlackChannel = 0x0008;
    int AlphaChannel = 0x0010;
    int OpacityChannel = 0x0010;
    int IndexChannel = 0x0020;             /* Color Index Table? */
    int ReadMaskChannel = 0x0040;          /* Pixel is Not Readable? */
    int WriteMaskChannel = 0x0080;         /* Pixel is Write Protected? */
    int MetaChannel = 0x0100;              /* not used */
    int CompositeMaskChannel = 0x0200;     /* SVG mask */
    int CompositeChannels = 0x001F;
    int AllChannels = 0x7ffffff;
    /*
      Special purpose channel types.
      FUTURE: are these needed any more - they are more like hacks
      SyncChannels for example is NOT a real channel but a 'flag'
      It really says -- "User has not defined channels"
      Though it does have extra meaning in the "-auto-level" operator
    */
    int TrueAlphaChannel = 0x0100; /* extract actual alpha channel from opacity */
    int RGBChannels = 0x0200;      /* set alpha from grayscale mask in RGB */
    int GrayChannels = 0x0400;
    int SyncChannels = 0x20000;    /* channels modified as a single unit */
    int DefaultChannels = AllChannels;
}
