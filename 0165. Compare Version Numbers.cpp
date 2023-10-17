#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Function to convert a string to an integer
    int customStoi(string token)
    {
        int sign = 1;
        if (token[0] == '-')
        {
            sign = -1;
        }
        int result = 0;

        int i = 0;
        while (i < token.length())
        {
            char ch = token[i];
            if (ch >= '0' && ch <= '9')
            {
                result = result * 10 + (ch - '0');
            }
            else
            {
                return 0; // Error: Non-digit character encountered
            }
            i++;
        }
        return result * sign;
    }

    // Function to split a version string into components and convert them to integers
    vector<int> convertToComponents(string version)
    {
        stringstream ss(version);
        vector<int> components;
        string token;
        while (getline(ss, token, '.'))
        {
            components.push_back(customStoi(token));
        }
        return components;
    }

public:
    // Function to compare two version strings
    int compareVersion(string version1, string version2)
    {
        // Convert version strings into components
        vector<int> ver1 = convertToComponents(version1);
        vector<int> ver2 = convertToComponents(version2);
        int maxLen = max(ver1.size(), ver2.size());

        // Compare version components
        for (int i = 0; i < maxLen; i++)
        {
            int element1 = (i < ver1.size()) ? ver1[i] : 0;
            int element2 = (i < ver2.size()) ? ver2[i] : 0;

            // Comparison Logic
            if (element1 < element2)
            {
                return -1;
            }
            else if (element1 > element2)
            {
                return 1;
            }
        }

        return 0; // Versions are equal
    }
};
