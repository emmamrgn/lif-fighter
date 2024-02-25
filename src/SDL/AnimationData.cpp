#include "AnimationData.h"
#include <fstream>
#include <sstream> 
#include <vector>
#include <string>

using namespace std;


AnimationData::AnimationData(){};

AnimationData::AnimationData(string CSVFile, string animationName)
    {
        AnimationName = animationName;
        vector<string> data;
        string line, value;
        ifstream file(CSVFile);

        while (getline(file,line))
        {
            if(line.rfind(animationName,0) != 0) //cherche animationName 
            {
                continue;
            }
            stringstream stream(line);
            while(getline(stream,value,';'))
            {
                data.push_back(value); //rajoute dans le vecteur
            } 
            NbFrames = stoi(data[1]);
            AnimationWidth = stoi(data[2]);
            AnimationHeight = stoi(data[3]);
            break;
        }

    }

AnimationData::~AnimationData(){};

void AnimationData::RegressionTest()
{
    AnimationData test("AnimationsRise.csv","Idle");
    if(test.AnimationName == "Idle" && test.NbFrames == 14 && test.AnimationWidth == 2828 && test.AnimationHeight == 378)
    {
        cout << "Regression Test OK" << endl;
    }
    else
    {
        cout << "Regression Test incorrect" << endl;
    }
}
