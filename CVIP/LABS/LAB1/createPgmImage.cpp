#include <bits/stdc++.h>
using namespace std;

void createPgmImage()
{
    ofstream fl;
    string magicNo;
    int w, h, maxIntensity;

    fl.open("FirstPgmImage.pgm");
    if (!fl)
    {
        cout << "File could not be opened." << endl;
        return;
    }

    magicNo = "P2";
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
            cin >> px;
            fl << px << " ";
        }
        fl << endl;
    }

    fl.close();
}

int main()
{
    createPgmImage();
    return 0;
}