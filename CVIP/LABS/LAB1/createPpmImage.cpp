#include <bits/stdc++.h>
using namespace std;

void createPpmImage()
{
    ofstream fl;
    string magicNo;
    int w, h, maxIntensity;

    fl.open("FirstPpmImage.ppm");
    if (!fl)
    {
        cout << "File could not be opened." << endl;
        return;
    }

    magicNo = "P3";
    cout << "Enter Height: ";
    cin >> h;
    cout << "Enter Width: ";
    cin >> w;
    cout << "Enter Max Intensity: ";
    cin >> maxIntensity;

    // Write in a file
    fl << magicNo << endl;
    fl << w << " " << h << endl;
    fl << maxIntensity << endl;

    int px;
    cout << "Enter data for " << h << " * " << w << " :" << endl;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cin >> px;
                fl << px << " ";
            }
            fl << endl;
        }
    }

    fl.close();
}

int main()
{
    createPpmImage();
    return 0;
}