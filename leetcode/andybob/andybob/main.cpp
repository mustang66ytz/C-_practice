//
//  main.cpp
//  andybob
//
//  Created by Yang Taozheng on 6/5/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<string> split_string(string);
int findMax(vector<int>);

// Complete the gamingArray function below.
int gamingArray(vector<int> arr) {
    int count = 0; //odd is andy, even is bob
    while(!arr.empty()){
        int maxPos = findMax(arr);
        arr.erase(arr.begin()+maxPos, arr.end());
        count++;
    }
    if(count%2 == 0){
        return 1; //andy wins
    }
    else{
        return 2; //bob wins
    }
}

int findMax(vector<int> arr){
    int max = INT_MIN;
    int maxPos = 0;
    for(int i=0; i<arr.size(); i++){
        if(max<=arr[i]){
            max = arr[i];
            maxPos = i;
        }
    }
    return maxPos;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (int g_itr = 0; g_itr < g; g_itr++) {
        int arr_count;
        cin >> arr_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        string arr_temp_temp;
        getline(cin, arr_temp_temp);
        
        vector<string> arr_temp = split_string(arr_temp_temp);
        
        vector<int> arr(arr_count);
        
        for (int i = 0; i < arr_count; i++) {
            int arr_item = stoi(arr_temp[i]);
            
            arr[i] = arr_item;
        }
        
        int result = gamingArray(arr);
        if(result == 1){
            cout<<"ANDY"<<endl;
        }
        else{
            cout<<"BOB"<<endl;
        }
        fout << result << "\n";
    }
    
    fout.close();
    
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });
    
    input_string.erase(new_end, input_string.end());
    
    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }
    
    vector<string> splits;
    char delimiter = ' ';
    
    size_t i = 0;
    size_t pos = input_string.find(delimiter);
    
    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));
        
        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }
    
    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));
    
    return splits;
}
