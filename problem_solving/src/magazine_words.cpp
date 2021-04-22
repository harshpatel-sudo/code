#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
int getWordIndex(string &str){
    if(str[0]>'@' && str[0]<'[')
        return str[0]-'A';
    if (str[0]>'`'&&str[0]<'{')
        return str[0]-71;
    return 0;
}

struct Node{
    string data;
    Node* next;
};

// Complete the checkMagazine function below.
void checkMagazine(vector<string> magazine, vector<string> note) {

    vector<Node*> magHash(52,nullptr);
    
    for (string& word : magazine){
        int index = getWordIndex(word);
        Node* temp = magHash[index];
        while(temp){
            temp=temp->next;
        }
        temp = new Node();
        temp->data=word;
        temp->next=magHash[index];
        magHash[index] = temp;
    }
    
    for (string & word : note){
        int index = getWordIndex(word);
        Node* temp = magHash[index];
        bool found = false;        
        while(temp){
            if (temp->data == word) {
                temp->data="";
                found = true;
                break;
            }
            temp = temp->next;
        }
        if (!found) {
            cout<< "No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
    return;
}

int main()
{
    string mn_temp;
    getline(cin, mn_temp);

    vector<string> mn = split_string(mn_temp);

    int m = stoi(mn[0]);

    int n = stoi(mn[1]);

    string magazine_temp_temp;
    getline(cin, magazine_temp_temp);

    vector<string> magazine_temp = split_string(magazine_temp_temp);

    vector<string> magazine(m);

    for (int i = 0; i < m; i++) {
        string magazine_item = magazine_temp[i];

        magazine[i] = magazine_item;
    }

    string note_temp_temp;
    getline(cin, note_temp_temp);

    vector<string> note_temp = split_string(note_temp_temp);

    vector<string> note(n);

    for (int i = 0; i < n; i++) {
        string note_item = note_temp[i];

        note[i] = note_item;
    }

    checkMagazine(magazine, note);

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
