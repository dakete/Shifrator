#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string box(string text){
  const unsigned char SBOX[] = { 0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01,
0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76, 0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59,
0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,0xb7, 0xfd, 0x93,
0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,0x04,
0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2,
0x75,0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29,
0xe3, 0x2f, 0x84,0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe,
0x39, 0x4a, 0x4c, 0x58, 0xcf,0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45,
0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38,
0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,0xcd, 0x0c, 0x13, 0xec, 0x5f,
0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,0x8c, 0xa1,
0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16 };
    
  string text2 = "";
     for (int i = 0; i < text.size(); ++i){
        text2 += SBOX[(unsigned char)text[i]];
    }
    return text2;
}

string revBox(string text){
  const unsigned char SBOX[] = { 82, 9, 106, 213, 48, 54, 165, 56, 191, 64, 163, 158, 129, 243, 215, 251, 124, 227, 57, 130, 155, 47, 255, 135, 52, 142, 67, 68, 196, 222, 233, 203, 84, 123, 148, 50, 166, 194, 35, 61, 238, 76, 149, 11, 66, 250, 195, 78, 8, 46, 161, 102, 40, 217, 36, 178, 118, 91, 162, 73, 109, 139, 209, 37, 114, 248, 246, 100, 134, 104, 152, 22, 212, 164, 92, 204, 93, 101, 182, 146, 108, 112, 72, 80, 253, 237, 185, 218, 94, 21, 70, 87, 167, 141, 157, 132, 144, 216, 171, 0, 140, 188, 211, 10, 247, 228, 88, 5, 184, 179, 69, 6, 208, 44, 30, 143, 202, 63, 15, 2, 193, 175, 189, 3, 1, 19, 138, 107, 58, 145, 17, 65, 79, 103, 220, 234, 151, 242, 207, 206, 240, 180, 230, 115, 150, 172, 116, 34, 231, 173, 53, 133, 226, 249, 55, 232, 28, 117, 223, 110, 71, 241, 26, 113, 29, 41, 197, 137, 111, 183, 98, 14, 170, 24, 190, 27, 252, 86, 62, 75, 198, 210, 121, 32, 154, 219, 192, 254, 120, 205, 90, 244, 31, 221, 168, 51, 136, 7, 199, 49, 177, 18, 16, 89, 39, 128, 236, 95, 96, 81, 127, 169, 25, 181, 74, 13, 45, 229, 122, 159, 147, 201, 156, 239, 160, 224, 59, 77, 174, 42, 245, 176, 200, 235, 187, 60, 131, 83, 153, 97, 23, 43, 4, 126, 186, 119, 214, 38, 225, 105, 20, 99, 85, 33, 12, 125 };
    
  string text2= "";
  for (int i = 0; i < text.size(); ++i){
    text2 += SBOX[(unsigned char)text[i]];
  }
  return text2;
}

string gammaCode(string text,string key){
  string res = "";
  for (int i = 0; i < text.size(); ++i) res+= text[i]^key[i%key.size()];
  return res; //побитовое исключение(слияние)
}

string shifr(string text, string password){
  string s,s2 = "";
  s = gammaCode(text, password);
  s = box(s);
  s2 = s[s.size()-1];
  for (int i = 0; i<s.size()-1; ++i) s2.push_back(s[i]);
  return s2;
}

string deshifr (string s, string password){
  string res,text,s2="";
  for (int i = 1; i < s.size(); ++i)s2.push_back(s[i]);
  s2.push_back(s[0]);
  text= revBox(s2);
  res = gammaCode(text,password);
  return res;
}

int main(){
    string command, text, pass, s, linet2, linet3, linet1, soob;
    cout << "*~Алгортим Диффи-Хэллмана~*" << endl << endl;
    cout << "Информация по командам:\n>> Шифровать - шифрует данные\n>> Расшифровать - расшифровывает данные\n>> Стоп - завершает работу программы:\n " << endl;
    for(int l = 0; l < 1; l++){
        ofstream fin("t1.txt");
        ofstream fout("t2.txt");
        
        if (fin.is_open() and fout.is_open()){
            cout << "Файл открыт" << endl << "Запишите данные:" << endl;
            getline(cin, soob);
            fin << soob;
            fout << soob;
            fin.close();
            fout.close();
        }
    }
    
    while (command != "."){
        cout << "Введите необходимую команду >> ";
        cin >> command;
        
        if (command=="Шифровать"){
            cout << "Введите пароль: ";
            cin >> pass;
            ifstream fin("t1.txt");
            ofstream fout("t2.txt");
            getline(fin, text);
            fin >> text;
            s = shifr(text,pass);
            pass = "";
            fout << s;
            fin.close();
            fout.close();
        }
        
        if (command=="Расшифровать"){
            cout << "Введите пароль для зашифрованого сообщения: ";
            ifstream fin("t2.txt");
            ofstream fout("t3.txt");
            cin >> pass;
            fin >> s;
            fout << deshifr(s,pass);
            fin.close();
            fout.close();
        }
        
        if (command == "Стоп"){
            ifstream fun("t1.txt");
            ifstream fin("t2.txt");
            ifstream fout("t3.txt");
            if (fun.is_open() and fout.is_open() and fout.is_open()){
                
                while (getline(fun, linet1)){
                    cout << "Содержимое (file t1) >> " << linet1 << endl;
                }
                
                while (getline(fin, linet2)){
                    cout << "Содержимое (file t2) >> " << linet2 << endl;
                }
                
                while (! fout.eof()){
                    getline (fout,linet3);
                    cout << "Содержимое (file t3) >> " << linet3 << endl;
                }
                
                return 0;
            }
        }
    }
}



