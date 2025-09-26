#pragma once

enum IWDType
{
    IWDT_NONE,
    IWDT_DIRECTIONS,
    IWDT_DIRECTIONS_HALF,
    IWDT_DIRECTIONS_RH2,
    IWDT_DIRECTIONS_RH3,
    IWDT_UP_DOWN_DIRECTIONS,
    IWDT_FULL_DIRECTIONS,
    // I am handling this case in a special manner because it is painful to do otherwise
    // Because of grav flip mechanic, relying on the value of Y becomes problematic so hardcode correct Y instead
    IWDT_CG_DROP,
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

typedef struct
{
    u8 x_high;
    u8 x_low;
    u8 z_high;
    u8 z_low;
    u8 y_high;
    u8 y_low;
    f32 y_value;
} IWDirectionFullAreas;

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

typedef struct
{
    IWDHeader header;
    IWDirectionFullAreas areas;
} IWDirectionFullAreasDesc;
