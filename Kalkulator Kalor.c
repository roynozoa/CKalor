#include <stdio.h>
#include <stdlib.h>

char comm;
char awal, akhir;
int input;
int kalorlebur=336000;
int kalorair=4200;
int kaloruap=2260000;
/*Ketiga kalor tersebut merupakan konstanta yang disediakan dalam program*/
int q, massa, delta;
/*q menyatakan kalor, delta menyatakan perubahan suhu yang besarannya dalam satuan Kelvin atau Celcius*/

int main () {
	printf ("====================");
	printf ("\n||Kalkulator Kalor||");
	printf ("\n====================");
	printf ("\n1. Start");
	printf ("\n2. Help");
	printf ("\n3. Exit");
	/*Input yang dimasukkan dalam bentuk integer. Misalnya jika ingin memilih Start, maka inputnya adalah 1.*/
	printf ("\nMasukkan angka sesuai dengan perintah yang ingin dieksekusi: ");
	scanf (" %c", &comm);
	command ();
}

command () {
	/*Digunakan untuk melanjutkan program sesuai input awal user.*/
	system ("CLS");
	if (comm=='1')
	{
		start();
	}
	else if (comm=='2')
	{
		helpset();
	}
	else if (comm=='3')
	{
		return 0;
	}
	else
	{
		error ();
	}
}

error () {
	printf ("\nInput yang anda masukkan salah.");
	printf ("\nProgram ini digunakan untuk menghitung kalor dan variabel lainnya pada perubahan wujud air.");
	printf ("\nTekan 1 untuk memulai program dan tekan 3 untuk keluar.");
	printf ("\nPerintah: ");
	scanf (" %c", &comm);
	command ();	
}

helpset () {
	printf ("\nProgram ini digunakan untuk menghitung kalor dan variabel lainnya pada perubahan wujud air.");
	printf ("\nTekan 1 untuk memulai program dan tekan 3 untuk keluar.");
	printf ("\nPerintah: ");
	scanf (" %c", &comm);
	command ();
}

start () {
	printf ("=============");
	printf ("\n||Wujud air||");
	printf ("\n=============");
	printf ("\n1. Padat");
	printf ("\n2. Cair");
	printf ("\n3. Gas");
	printf ("\nMasukkan wujud awal: ");
	scanf (" %c", &awal);
	printf ("\nMasukkan wujud akhir: ");
	scanf (" %c", &akhir);
	/*Program akan dilanjutkan berdasarkan wujud awal dan akhir karen adanya rumus yang berbeda-beda*/
	if (awal=='1')
	{
		if (akhir=='1')
		{
			stepice();
		}
		else if (akhir=='2')
		{
			icewater();
		}
		else if (akhir=='3')
		{
			totalstep();
		}
		else
		{
			wrong();
		}
	}
	else if (awal=='2')
	{
		if (akhir=='1')
		{
			icewater();
		}
		else if (akhir=='2')
		{
			stepwater();
		}
		else if (akhir=='3')
		{
			watergas();
		}
		else
		{
			wrong();
		}
	}
	else if (awal=='3')
	{
		if (akhir=='1')
		{
			totalstep();
		}
		else if (akhir=='2')
		{
			watergas();
		}
		else if (akhir=='3')
		{
			stepgas();
		}
		else
		{
			wrong();
		}
	}
	else
	{
		wrong();
	}
}

wrong() {
	/*Apabila input dari user salah, maka user akan diminta untuk menginput dari awal*/
	system ("CLS");
	printf ("Input yang dimasukkan salah.");
	secondhelp ();
}

secondhelp () {
	/*Usai menggunakan program, user akan ditanya apakah ingin menggunakannya kembali atau tidak*/
	printf ("\n\n===========================================================================================");
	printf ("\n\n1. Lanjut");
	printf ("\n2. Bantuan");
	printf ("\n3. Keluar");
	printf ("\nPerintah: ");
	scanf (" %c", &comm);
	command ();
}

/*Untuk beberapa modular berikut, munculnya variabel berdasarkan rumus kalor yang ada, nilai variabel lainnya ditentukan oleh user 
kecuali beberapa konstanta seperti yang sudah tertera di awal program*/
stepice() {
	printf ("\n\n============");
	printf ("\n||Variabel||");
	printf ("\n============");
	printf ("\n1. Kalor (satuan Joule)");
	printf ("\n2. Massa (satuan kilogram)");
	printf ("\nMasukkan variabel yang ingin dicari: ");
	scanf (" %c", &input);
	if (input=='1')
	{
		printf ("\nMasukkan massa es dalam kilogram: ");
		scanf (" %d", &massa);
		q=massa*kalorlebur;
		printf ("\nKalor yang diperlukan atau dihasilkan adalah sebesar %d Joule", q);
		secondhelp ();
	}
	else if (input=='2')
	{
		printf ("\nMasukkan kalor yang dihasilkan: ");
		scanf (" %d", &q);
		massa=q/kalorlebur;
		printf ("\nMassa es adalah sebesar %d kilogram.", massa);
		secondhelp ();
	}
	else
	{
		wrong ();
	}
}

stepgas() {
	printf ("\n\n============");
	printf ("\n||Variabel||");
	printf ("\n============");
	printf ("\n1. Kalor (satuan Joule)");
	printf ("\n2. Massa (satuan kilogram)");
	printf ("\nMasukkan variabel yang ingin dicari: ");
	scanf (" %c", &input);
	if (input=='1')
	{
		printf ("\nMasukkan massa dalam kilogram: ");
		scanf (" %d", &massa);
		q=massa*kaloruap;
		printf ("\nKalor yang diperlukan atau dihasilkan adalah sebesar %d Joule", q);
		secondhelp ();
	}
	else if (input=='2')
	{
		printf ("\nMasukkan kalor yang dihasilkan: ");
		scanf (" %d", &q);
		massa=q/kaloruap;
		printf ("\nMassa adalah sebesar %d kilogram.", massa);
		secondhelp ();
	}
	else
	{
		wrong ();
	}
}

stepwater() {
	printf ("\n\n============");
	printf ("\n||Variabel||");
	printf ("\n============");
	printf ("\n1. Kalor (satuan Joule)");
	printf ("\n2. Massa (satuan kilogram)");
	printf ("\n3. Perubahan suhu (satuan Celcius atau Kelvin)");
	printf ("\nMasukkan variabel yang ingin dicari: ");
	scanf (" %c", &input);
	if (input=='1')
	{
		printf ("\nMasukkan massa dalam kilogram: ");
		scanf (" %d", &massa);
		printf ("\nMasukkan besar perubahan suhu: ");
		scanf (" %d", &delta);
		if (delta>100)
		{
			wrong ();
		}
		else
		{
			q=massa*kalorair*delta;
			printf ("\nKalor yang diperlukan atau dihasilkan adalah sebesar %d Joule", q);
		}
	}
	else if (input=='2')
	{
		printf ("\nMasukkan kalor yang dihasilkan: ");
		scanf (" %d", &q);
		printf ("\nMasukkan besar perubahan suhu: ");
		scanf (" %d", &delta);
		massa=q/(kalorair*delta);
		printf ("\nMassa adalah sebesar %d kilogram", massa);
	}
	else if (input=='3')
	{
		printf ("\nMasukkan kalor yang dihasilkan: ");
		scanf (" %d", &q);
		printf ("\nMasukkan massa dalam kilogram: ");
		scanf (" %d", &massa);
		delta=q/(kalorair*massa);
		printf ("\nPerubahan suhu adalah sebesar %d Celcius", delta);
	}
	else 
	{
		wrong ();
	}
	secondhelp();
}


/*Untuk ketiga modular berikut, variabel yang dicari adalah kalor pada reaksi*/
icewater() {
	printf ("\nMasukkan massa dalam kilogram: ");
	scanf (" %d", &massa);
	
	/*Pada suatu reaksi perubahan kalor, perubahan suhu hanya dihitung pada wujud cair.*/
	printf ("\nMasukkan besar perubahan suhu pada wujud cair: ");
	scanf (" %d", &delta);
	
	q=(massa*kalorlebur)+(massa*kalorair*delta);
	printf ("\nKalor yang diperlukan atau dihasilkan adalah sebesar %d Joule", q);
	secondhelp();
}

watergas() {
	printf ("\nMasukkan massa dalam kilogram: ");
	scanf (" %d", &massa);
	
	/*Pada suatu reaksi perubahan kalor, perubahan suhu hanya dihitung pada wujud cair.*/
	printf ("\nMasukkan besar perubahan suhu pada wujud cair: ");
	scanf (" %d", &delta);
	
	q=(massa*kaloruap)+(massa*kalorair*delta);
	printf ("\nKalor yang diperlukan atau dihasilkan adalah sebesar %d Joule", q);
	secondhelp();
}

totalstep () {
	printf ("\nMasukkan massa dalam kilogram: ");
	scanf (" %d", &massa);
	delta=100;
	q=(massa*kalorlebur)+(massa*kalorair*delta)+(massa*kaloruap);
	printf ("\nKalor yang diperlukan atau dihasilkan adalah sebesar %d Joule", q);
	secondhelp();
}
