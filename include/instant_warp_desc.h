#pragma once

enum IWDType
{
    IWDT_NONE,
    IWDT_DIRECTIONS,
    IWDT_DIRECTIONS_HALF,
    IWDT_UP_DOWN_DIRECTIONS,
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
