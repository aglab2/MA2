#pragma once

enum IWDType
{
    IWDT_DIRECTIONS,
    IWDT_UP_DOWN_DIRECTIONS,
};

// MARK: Areas tools
typedef struct
{
    u8 x_high;
    u8 x_low;
    u8 z_high;
    u8 z_low;
} IWDirectionAreas;

typedef struct
{
    IWDirectionAreas y_high;
    IWDirectionAreas y_low;
} IWDirectionUpDownDirectionsAreas;

// MARK: Descriptors
typedef struct
{
    u8 type; // IWDType
} IWDHeader;

typedef struct
{
    IWDHeader header;
    IWDirectionAreas areas;
} IWDirectionAreasDesc;

typedef struct
{
    IWDHeader header;
    IWDirectionUpDownDirectionsAreas areas;
} IWDirectionUpDownDirectionsAreasDesc;
