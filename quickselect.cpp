#include <iostream>
#include <ctime>
using namespace std;

template<class T>
T median( T *array, int n ){
	int i,j;
	int l = 0, r = n - 1, m = (n-1)/2;
	for(;;){
		for( int ii=0; ii<n; ii++ )
			cout<< "["<<ii<<"]" <<array[ii] <<","<<flush;
		cout<<endl;
		cout<< "l" << l << " r" << r  << " m"<< m<<endl;

		i = l - 1, j = r;
		for(;;){
			if( r <= l )
				return array[(n-1)/2];

			do{
				i++;
			}while( array[i] < array[r] );
			do{
				j--;
			}while( array[j] > array[r] );
			if( i >= j ) break;
			cout<< "swap:" << i << "<->" << j <<endl;
			T tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
		cout<< "swap:" << i << "<->" << r <<endl;
		T tmp = array[i];
		array[i] = array[r];
		array[r] = tmp;

		if( i > l + m - 1 ){
			r = i - 1;
		}
		else {
			l = i+1;
			m = m - i;
		}
		
	}
}

template<class T>
T median2( T *array, int n ){
	int i,j;
	int l = 0, r = n - 1, m = (n-1)/2;
	for(;;){
		for( int ii=0; ii<n; ii++ )
			cout<< "["<<ii<<"]" <<array[ii] <<","<<flush;
		cout<<endl;
		cout<< "l" << l << " r" << r  << " m"<< m<<endl;

		i = l - 1, j = r;
		for(;;){
			if( r <= l )
				return array[m];

			do{
				i++;
			}while( array[i] < array[r] );
			do{
				j--;
			}while( array[j] > array[r] );
			if( i >= j ) break;
			cout<< "swap:" << i << "<->" << j <<endl;
			T tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
		cout<< "swap:" << i << "<->" << r <<endl;
		T tmp = array[i];
		array[i] = array[r];
		array[r] = tmp;

		if( i > m - 1 ){
			r = i - 1;
		}
		else {
			l = i+1;
		}
		
	}
}


int main(){
	int a[] = {4,2,11,9,39,6,1,5};
	int size = 5;

	for( int i=0; i<size; i++ )
		cout<< "["<<i<<"]"<<a[i] << ","<<flush;
	cout<<endl;

	cout<< median2( a, size ) <<endl;
	for( int i=0; i<size; i++ )
		cout<< "["<<i<<"]"<<a[i] << ","<<flush;
	cout<<endl;
}
