 #include <iostream>
 #include <string>
 #include <cmath>
using namespace std;

string encrypt(string text, int tranpose_column){
	// Panjang baris
	int tranpose_row = ceil((double) text.length()/tranpose_column);
	char arr_text_tranpose[tranpose_row][tranpose_column] = {(char) 0};
	int row = 0;
	int column = 0;
	string encrypted_text = "";
	
	for(char character: text){
		arr_text_tranpose[row][column] = character;
		// cout << arr_text_tranpose[row][column];
		// cout << row << " " << column << " " << character << endl;
		column++;
		if(column == tranpose_column){
			row++;
			column = 0;
		}
	}
	for(int i = 0; i < tranpose_column; i++){
		for(int j = 0; j < tranpose_row; j++){
			if(arr_text_tranpose[j][i] == (char) 0){
				break;
			}
			encrypted_text += arr_text_tranpose[j][i];
		}
	}
	return encrypted_text;

}

string dencrypt(string encrypted_text,int tranpose_column){
	// Panjang Baris
	int tranpose_row = ceil((double) encrypted_text.length()/tranpose_column);
	char arr_text_tranpose[tranpose_row][tranpose_column] = {(char) 0};
	int row = 0;
	int column = 0;
	string decrypted_text = "";

	for(char character: encrypted_text){
		if(row == tranpose_row - 1){
			if(row * tranpose_column + column >= encrypted_text.length()){
				cout << row << " ";
				cout << character << endl;
				row = 0;
				column++;
			}
		}
		arr_text_tranpose[row][column] = character;
		// cout << arr_text_tranpose[row][column];
		// cout << row << " " << column << " " << character << endl;
		row++;
		if(row == tranpose_row){
			column++;
			row = 0;
		}
	}

	for(int i = 0; i < tranpose_row; i++){
		for(int j = 0; j < tranpose_column; j++){
			if(arr_text_tranpose[i][j] == (char) 0){
				break;
			}
			decrypted_text += arr_text_tranpose[i][j];
		}
	}
	return decrypted_text;
}

int main() {
	string text;
	int tranpose_column;
	cout << " Massukkan teks yang anda inginkan: " << endl;
	getline(cin, text);
	cout << " Banyak kolom yang diperlukan" << endl;
	cin >> tranpose_column;

	string text_encrypt = encrypt(text,tranpose_column);
	string text_decrypt = dencrypt(text_encrypt,tranpose_column);
	cout << " Text Encrypt  = " << text_encrypt << endl;
	cout << " Text Decrypt  = " << text_decrypt << endl;
	
	return 0;
} 
