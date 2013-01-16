#ifndef _PATTERN_H_
#define _PATTERN_H_

float trainI[10][63]={ {0,0,0,0,0,0,0,  //0
                        0,1,1,1,1,1,0,
                        0,1,0,0,0,1,0,
                        0,1,0,0,0,1,0,
                        0,1,0,0,0,1,0,
                        0,1,0,0,0,1,0,
                        0,1,0,0,0,1,0,
                        0,1,1,1,1,1,0,
                        0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,  //1
                        0,0,0,1,0,0,0,
                        0,0,1,1,0,0,0,
                        0,0,0,1,0,0,0,
                        0,0,0,1,0,0,0,
                        0,0,0,1,0,0,0,
                        0,0,0,1,0,0,0,
                        0,1,1,1,1,1,0,
                        0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,  //2
                        0,1,1,1,1,1,0,
                        0,0,0,0,0,1,0,
                        0,0,0,0,0,1,0,
                        0,1,1,1,1,1,0,
                        0,1,0,0,0,0,0,
                        0,1,0,0,0,0,0,
                        0,1,1,1,1,1,0,
                        0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,  //3
                        0,1,1,1,1,1,0,
                        0,0,0,0,0,1,0,
                        0,0,0,0,0,1,0,
                        0,0,0,1,1,1,0,
                        0,0,0,0,0,1,0,
                        0,0,0,0,0,1,0,
                        0,1,1,1,1,1,0,
                        0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,  //4
                        0,1,0,0,0,0,0,
                        0,1,0,0,0,0,0,
                        0,1,0,1,0,0,0,
                        0,1,1,1,1,0,0,
                        0,0,0,1,0,0,0,
                        0,0,0,1,0,0,0,
                        0,0,0,1,0,0,0,
                        0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,  //5
                        0,1,1,1,1,1,0,
                        0,1,0,0,0,0,0,
                        0,1,0,0,0,0,0,
                        0,1,1,1,1,1,0,
                        0,0,0,0,0,1,0,
                        0,0,0,0,0,1,0,
                        0,1,1,1,1,1,0,
                        0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,  //6
                        0,1,1,1,1,1,0,
                        0,1,0,0,0,0,0,
                        0,1,0,0,0,0,0,
                        0,1,1,1,1,1,0,
                        0,1,0,0,0,1,0,
                        0,1,0,0,0,1,0,
                        0,1,1,1,1,1,0,
                        0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,  //7
                        0,1,1,1,1,1,0,
                        0,0,0,0,0,1,0,
                        0,0,0,0,1,0,0,
                        0,0,0,1,0,0,0,
                        0,0,1,0,0,0,0,
                        0,1,0,0,0,0,0,
                        0,1,0,0,0,0,0,
                        0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,  //8
                        0,1,1,1,1,1,0,
                        0,1,0,0,0,1,0,
                        0,1,0,0,0,1,0,
                        0,1,1,1,1,1,0,
                        0,1,0,0,0,1,0,
                        0,1,0,0,0,1,0,
                        0,1,1,1,1,1,0,
                        0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,  //9
                        0,1,1,1,1,1,0,
                        0,1,0,0,0,1,0,
                        0,1,0,0,0,1,0,
                        0,1,1,1,1,1,0,
                        0,0,0,0,0,1,0,
                        0,0,0,0,0,1,0,
                        0,0,0,0,0,1,0,
                        0,0,0,0,0,0,0} };

float trainO[10][9]={   {0,0,0,0,0,0,0,0,0},
                        {1,0,0,0,0,0,0,0,0},
                        {0,1,0,0,0,0,0,0,0},
                        {0,0,1,0,0,0,0,0,0},
                        {0,0,0,1,0,0,0,0,0},
                        {0,0,0,0,1,0,0,0,0},
                        {0,0,0,0,0,1,0,0,0},
                        {0,0,0,0,0,0,1,0,0},
                        {0,0,0,0,0,0,0,1,0},
                        {0,0,0,0,0,0,0,0,1}  };

float testI[10][63]={  {0,0,0,0,0,0,0,  //falsified 0
                        0,1,0,1,1,0,0,
                        0,0,0,0,0,1,1,
                        0,1,0,0,0,1,0,
                        0,1,0,0,0,1,0,
                        0,1,0,0,0,1,0,
                        0,1,0,0,0,1,0,
                        0,1,1,1,1,1,0,
                        0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,  //falsified 1
                        0,0,0,1,0,0,0,
                        0,0,0,0,0,0,0,
                        0,0,0,1,0,0,0,
                        0,0,0,1,0,0,0,
                        0,0,0,1,0,0,0,
                        0,0,0,1,0,0,0,
                        0,0,1,1,0,0,0,
                        0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,  //falsified 2
                        0,1,1,1,1,1,0,
                        0,0,0,0,0,1,0,
                        0,0,0,0,0,1,0,
                        0,1,1,0,1,1,0,
                        0,1,0,0,0,0,0,
                        0,1,0,0,0,0,0,
                        0,1,0,1,1,1,0,
                        0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,  //falsified 3
                        0,1,1,1,1,1,0,
                        0,0,0,0,0,1,0,
                        0,0,0,0,0,1,0,
                        0,0,0,1,1,0,0,
                        0,0,0,0,0,1,0,
                        0,0,0,0,0,1,0,
                        0,1,0,1,1,1,0,
                        0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,  //falsified 4
                        0,1,0,0,0,0,0,
                        0,1,0,0,0,0,0,
                        0,1,0,1,0,0,0,
                        0,0,1,0,1,0,0,
                        0,0,0,1,0,0,0,
                        0,0,0,1,0,0,0,
                        0,0,0,1,0,0,0,
                        0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,  //falsified 5
                        0,1,1,1,1,1,0,
                        0,1,0,0,0,0,0,
                        0,1,0,0,0,0,0,
                        0,0,1,1,1,1,0,
                        0,0,0,0,0,0,0,
                        0,0,0,0,0,1,0,
                        0,1,1,1,1,1,0,
                        0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,  //falsified 6
                        0,1,1,1,1,1,0,
                        0,0,0,0,0,0,0,
                        0,1,0,0,0,0,0,
                        0,1,1,1,1,1,0,
                        0,1,0,0,0,1,0,
                        0,1,0,0,0,1,0,
                        0,0,1,1,1,1,0,
                        0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,  //falsified 7
                        0,1,0,1,1,1,0,
                        0,0,0,0,0,1,0,
                        0,0,0,0,1,0,0,
                        0,0,0,1,0,0,0,
                        0,0,0,0,0,0,0,
                        0,1,0,0,0,0,0,
                        0,1,0,0,0,0,0,
                        0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,  //falsified 8
                        0,1,1,1,1,1,0,
                        0,1,0,0,0,1,0,
                        0,1,0,0,0,1,0,
                        0,0,1,1,1,1,0,
                        0,1,0,0,0,1,0,
                        0,1,0,0,0,1,0,
                        0,0,1,1,1,1,0,
                        0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,  //falsified 9
                        0,0,1,1,1,1,0,
                        0,1,0,0,0,1,0,
                        0,1,0,0,0,1,0,
                        0,1,1,1,1,0,0,
                        0,0,0,0,0,1,0,
                        0,0,0,0,0,1,0,
                        0,0,0,0,0,1,0,
                        0,0,0,0,0,0,0} };


#endif /* PATTERN_H_ */
