//�������� 1ĭ�� �ű�� 
for(int i=0;i<s.size();i++){
   	for (int j = s.size()-1; j >0; j--) {
       	int temp = s[j];
        s[j] = s[j-1];
        s[j-1] = temp;
	}
}
