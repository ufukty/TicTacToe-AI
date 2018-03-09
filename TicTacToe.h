/*
	TicTacToe v2.1

	Ufuktan Yıldırım
	14290070
	ufukty@gmail.com

	------------------------------ Notlar ------------------------------

	*	4 x 4 boyutta ilk hamle için gereken hesaplama 3 x 3 için
		gerekenin 360 bin katı. 4 x 4 ve 5 x 5'lik oyun için orta zorluk
		seviyesiyle başlayıp ilerleyen ellerde H tuşuna basarak
		alpha/beta'dan hamle tavsiyesi alınabilir.

	*	Alfa/beta algoritması, node'ların saklanmaması nedeniyle her
		elde tekrar hesap yapıyor. Önceki implementasyonu her node'u
		saklayacak şekilde gerçekleştirmiştim ancak hafıza sorunlarını
		çözemedim.

	*	Alpha/beta algoritması iki taraftan sıkıştırmalı hamle karşısında
		ne yaparsa yapsın kaybedeceği için engellemeye çalışmıyor, alakasız
		bir hamle öneriyor. Bu durumla karşılaşmak için ilk ellerde kötü
		hamleler seçip sonrasında alfa/betadan öneri almanız için H'ye basın.

	*	Çalıştırma videosu: https://youtu.be/X9GnQvv_bo4

	----------------------------- Genel Yapı -----------------------------

	Board sınıfı
		n x n boyutta* tahtayı temsil eder; tahtanın durumunu hesaplayan, 
		mümkün hamleleri hesaplayan, tahtayı successor'lerine götüren, 
		yapılan hamleleri geri alabilen metodları içerir.

	UI sınıfı
		Menü ekranlarını ve oyun ekranını en güncel haliyle çizmek için
		gereken metodları içerir.

	UserHandler sınıfı
		Kullanıcıdan karakter girdi alıp komut şeklinde döndürür.

	Decision sınıfı (Alpha/Beta)
		Argüman aldığı tahta üzerinde gereken hesaplamaları yapıp geri
		döndüren 3 zorluğa sahip metodlar içerir.

	TicTacToe sınıfı
		Diğer 4 sınıfı birleştirir, aralarındaki iletişimi sağlar.


	----------------------------- Zor seviye -----------------------------

	Karar algoritması argüman olarak aldığı tahtaya bakıp sıradaki oyuncu için
	gerekli olan alfa/beta algoritmasını (yani max yada min'i) çağırıyor.

	Alpha/beta algoritmaları her bir tahta için bir sonraki muhtemel pozisyona
	alıyor ve hesaplaması bittiğinde tahtayı eski haline getiriyor. Bunun için
	Board sınıfı içinde değişikliklerin kaybedildiği bir dizi ve bir adım geri
	almayı sağlayan bir metod var. Hesaplama sırasında node'lar ayrıca 
	saklanmadığı için her elde tekrar hesaplama yapılmak zorunda.

	Değer biçme fonksiyonu tahtaları X'in kazandığı durumda pozitif sayılarla, 
	O'nun kazandığı durumundlarda negatif sayılarla ifade ediyor. Daha kısa
	ellerle kazanıldığında sayıların değeri mutlak değerce artıyor. Berabere
	kalma durumu ancak son elde gerçekleşebileceği için 0'la ifade edilmesi
	yeterli geldi.

	     -5    -4    -3    -2    -1     0     1     2     3     4     5
    <-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+----->
	      |                             |                             |
    O'nun 5. elde                   Berabere                    X'in 5. elde
      kazanması                                                   kazanması

	----------------------- Kolay ve orta seviye --------------------------

	1. sınıf C++ dersindeki TicTacToe ödevindeki algoritmadan aynen uygulandı.
*/


#pragma once

#include "TicTacToeMacros.h"
#include "TicTacToeStructures.h"

#include "TicTacToeBoard.h"
#include "TicTacToeUI.h"
#include "TicTacToeDecision.h"
#include "TicTacToeUserHandler.h"

namespace TicTacToe {

	class TicTacToe : public UI, public Decision, public UserHandler {
	public:

		TicTacToe(void);

		void enable_logs(void);
		void reset_pointer(void);
		bool start_game(void);

	private:

		Game_Data game;

		void prepare_for_start();
		void print_log(std::string);
		void menu(void);
		void play(void);

	};

}