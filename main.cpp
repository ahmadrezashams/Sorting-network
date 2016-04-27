#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
bool sorted(vector<int> &Numbers)
{
    for (int i = 0; i < Numbers.size() - 1; i++)
        if (Numbers[i]>Numbers[i + 1])
            return false;
    return true;
}

bool is_valid_network(vector<string>  Network, int num_of_stages)
{
    for (int j = 0; j < num_of_stages; j++)
    {
        for (int i = 0; i < Network.size(); i++)
        {
            if (Network[i][j] == '-')
                continue;
            int count = 0;
            for (int k = 0; k < Network.size(); k++)
                if (Network[i][j] == Network[k][j])
                    count++;
            if (count != 2)
            {
                return false;
            }
        }
    }
    return true;
}
void  apply(vector<string>  &Network, int num_of_stages, vector<int>& Numbers)
{
    for (int j = 0; j < num_of_stages; j++)
    {
        for (int i = 0; i < Network.size() - 1; i++)
        {
            if (Network[i][j] == '-')
                continue;
            for (int k = i + 1; k < Network.size(); k++)
                if (Network[i][j] == Network[k][j])
                    if (Numbers[i]>Numbers[k])
                        swap(Numbers[i], Numbers[k]);
        }
    }
}
void slove(vector<string>  Network, vector<int> Numbers, int num_of_stages,int _case)
{
    cout << "Case #" << _case << ":" << endl;

    if (!is_valid_network(Network, num_of_stages))
    {
        cout << "Invalid network"<< endl;
        return;
    }
    apply(Network, num_of_stages, Numbers);
    if (sorted(Numbers))
        cout << "Sorted" << endl;
    else
        cout << "No Sorted" << endl;
}
int main()
{
    ifstream input("D:\\A.in");
    ofstream output("D:\\B.out");
    int T;
    int num_of_inputs, num_of_stages;
    input >> T;
    vector<int> Numbers;
    vector<string>  Network;
    string str;
    for (int k = 0; k < T; k++)
    {
        input >> num_of_inputs >> num_of_stages;
        for (int i = 0; i < num_of_inputs; i++)
        {
            string temp;
            input >> temp;
            Network.push_back(temp);
        }
        for (int j = 0; j < num_of_inputs; j++)
        {
            int temp;
            input >> temp;
            Numbers.push_back(temp);
        }
        slove(Network, Numbers, num_of_stages,k+1);
        Network.clear();
        Numbers.clear();
    }
    return 0;
}
