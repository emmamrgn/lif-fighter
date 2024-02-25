#include "Field.h"
#include <cassert>

//const char field1[9][33] =
const char field1[22][50] =
{
"#################################",
"#                               #",
"#                               #",
"#                               #",
"#                               #",
"#                               #",
"#                               #",
"#                               #",
"#################################"
};


Field::Field()
{
    f_dimx = 50;
    f_dimy = 22;
    for(int x=0;x<f_dimx; ++x)
    {
        for(int y=0; y<f_dimy; ++y)
        {
            switch(field1[f_dimy-1-y][x]) {
            	case '#': field[x][y] = WALL; 
                break;
				case ' ': field[x][y] = SPACE; 
                break;
            }
        }
    }
}

bool Field::isPositionValid(const int x, const int y) const
{
    return ((x>=0) && (x<f_dimx) && (y>=0) && (y<f_dimy) && (field[x][y]!='#'));
}

int Field::getDimX() const
{
    return f_dimx;
}
int Field::getDimY() const
{
    return f_dimy;
}

void Field::RegressionTest()
{
    assert(isPositionValid(0,0)==false);
    assert(isPositionValid(1,1)==true);
    assert(isPositionValid(33,8)==false);
    assert(isPositionValid(32,7)==true);
}