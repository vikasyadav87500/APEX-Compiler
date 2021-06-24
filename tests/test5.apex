void main() {
	int odd = 0 ;
	int even = 0 ;
    int n = 11;

    int e = 0;
	for ( int i = 1 ; i <= n ; i++ ){
		if( e == 0 ){
			e = 1;
            odd++;
		}else{
			e = 0 ;
            even++;
		}
	}
}

// if else inside for loop
