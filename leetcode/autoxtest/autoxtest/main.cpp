//
//  main.cpp
//  autoxtest
//
//  Created by Yang Taozheng on 6/5/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// Complete the getType function below.
vector<string> getType(vector<string> abc) {
    int numCase = abc.size();
    vector<string> res;
    vector<vector<int>> digits(numCase);
    
    for(int i=0; i<numCase; i++){
        string temp;
        for(int j=0; j<abc[i].length(); j++){
            if(abc[i][j] == ' '){
                digits[i].push_back(stoi(temp));
                temp.clear();
            }
            else{
                temp+=abc[i][j];
            }
        }
        digits[i].push_back(stoi(temp));
    }
    
    for(int i=0; i<numCase; i++){
        int a=digits[i][0];
        int b=digits[i][1];
        int c=digits[i][2];
        
        if(a+b>c && a+c>b && b+c>a){
            // it is a triangle
            if(a==b && a==c && b==c){
                res.push_back("Equilateral");
            }
            else if(a==b||a==c||b==c){
                res.push_back("Isosceles");
            }
            else{
                res.push_back("None of these");
            }
        }
        else{
            res.push_back("None of these");
        }
    }
    
    return res;
    
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    int abc_count;
    cin >> abc_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    vector<string> abc(abc_count);
    
    for (int i = 0; i < abc_count; i++) {
        string abc_item;
        getline(cin, abc_item);
        
        abc[i] = abc_item;
    }
    
    vector<string> res = getType(abc);
    
    for (int i = 0; i < res.size(); i++) {
        fout << res[i];
        cout<<res[i]<<endl;
        
        if (i != res.size() - 1) {
            fout << "\n";
        }
    }
    
    fout << "\n";
    
    fout.close();
    
    return 0;
}
