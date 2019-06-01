//#define _CRT_SECURE_NO_DEPRECATE // odczyt fstream , 

#include "headers.h"

Music music;
Music oryginalMusic;
Music effectsMusic;


void but_loadSound_cb(Fl_Widget* w, void*v)
{
	std::string name = ((Fl_Input*)v)->value();
	music.setFileName(name);
	music.loadSound();
	oryginalMusic.loadSound();
	std::cout << std::endl << "Button loadSound callback!" << std::endl;
}

void but_saveSound_cb(Fl_Widget* w, void*v)
{
	std::string name = ((Fl_Input*)v)->value();
	music.saveSound(name);

	std::cout << std::endl << "Button saveSound callback!" << std::endl;
}

void but_play_cb(Fl_Widget* w, void* v)
{
	music.playSoud();
	std::cout << std::endl << "Button play callback!" << std::endl;
}

void but_pause_cb(Fl_Widget* w, void* v)
{
	music.pauseSound();
	std::cout << std::endl << "Button pause callback!" << std::endl;
}

void but_loop_cb(Fl_Widget* w, void* v)
{
	music.loopSound();
	std::cout << std::endl << "Button loop callback!" << std::endl;
}

void but_stop_cb(Fl_Widget* w, void* v)
{
	music.stopSound();
	std::cout << std::endl << "Button stop callback!" << std::endl;
}

void but_rewind_cb(Fl_Widget* w, void* v)
{
	music.rewindSound();
	std::cout << std::endl << "Button rewind callback!" << std::endl;
}

void but_forward_cb(Fl_Widget* w, void* v)
{
	music.forwardSound();
	std::cout << std::endl << "Button forward callback!" << std::endl;
}


//slider
void but_volume_set_cb(Fl_Widget *w, void *v)
{
	music.setVolume(((Fl_Value_Slider*)v)->value());
}

void but_volumePlus_cb(Fl_Widget *w, void* v)
{
	music.volumePlus();
	std::cout << std::endl << "Button volume plus callback!" << std::endl;
}

void but_volumeMinus_cb(Fl_Widget *w, void* v)
{
	music.volumeMinus();
	std::cout << std::endl << "Button volume minus callback!" << std::endl;
}

void but_speedPlus_cb(Fl_Widget* w, void* v)
{
	music.speedPlus();
	std::cout << std::endl << "Button speed plus callback!" << std::endl;
}

void but_speedMinus_cb(Fl_Widget* w, void* v)
{
	music.speedMinus();
	std::cout << std::endl << "Button slow callback!" << std::endl;
}

 //########################################
 //CLOSE WINDOW
void but_exit_cb(Fl_Widget *w, void* v)
{
	if (fl_ask("Do you want to exit?"))
	{
		((Fl_Window*)v)->hide();//zamkniecie okna glownego win, przy pomocy wskaznika
	}
}


void but_echo_cb(Fl_Widget *w, void* v)
{
	std::cout << std::endl << "Button echo callback!" << std::endl;
	std::vector<sf::Int16> samples = ((Music*)v)->getSamples();
	//std::vector<sf::Int16> samples2;
	EffectHandle efect(EffectHandle::EffectType::ECHO);
	efect.effect(samples);
	effectsMusic.loadSamples(samples, music.fs);
}

void but_changeSound_cb(Fl_Widget *w, void* v)
{
	std::cout << std::endl << "Button change sound callback!" << std::endl;
	if (w->label() == "Original")
	{
		w->label("After effects");
		music = effectsMusic;
		//music.setSpeed(0.5f); // stereo channel , trzeba zmniejszyc odtwarrzanie fs
		std::cout << std::endl << "w->label() == Original" << std::endl;
	}
	else
	{ 
		w->label("Original");
		std::cout << std::endl << " w->label() == After effects " << std::endl;
		music = oryginalMusic;
		//music.setSpeed(1.f);
	}

}


int main()
{
	system("Color 0B");
	std::cout << "Efekt gitarowy - projekt" << std::endl;


	//Modulator ko³owy (Ring modulator) wprowadza efekt
	//silnie nieharmonicznego sygna³u, poprzez wymno¿enie
	//sygna³u przez sinus o regulowanej czêstotliwoœci


	Fl_Window win(500, 400);
	win.color(148);

	win.begin();

	Fl_Input fileName(110, 10, 100, 30, "@filenew Load Sound");
	fileName.callback(but_loadSound_cb,&fileName);
	fileName.color2(148);
	fileName.color(156);

	Fl_Input fileSaveName(350, 10, 100, 30, "@filenew Save Sound");
	fileSaveName.callback(but_saveSound_cb,&fileSaveName);
	fileSaveName.color2(148);
	fileSaveName.color(156);


	//Fl_Button but_loadSound(10, 10, 110, 30, "@filenew Load Sound");
	//but_loadSound.shortcut('l');
	//but_loadSound.callback(but_loadSound_cb);
	//but_loadSound.color2(156);
	//but_loadSound.color(156);


	Fl_Button but_changeSound(130, 90, 90, 30, "Original");
	but_changeSound.shortcut('c');
	but_changeSound.callback(&but_changeSound_cb);
	but_changeSound.color2(156);
	but_changeSound.color(156);


	//Fl_Button but_saveSound(10, 170, 110, 30, "@filenew Save Sound");
	//but_loadSound.shortcut('s');
	//but_saveSound.callback(but_saveSound_cb, &music);
	//but_saveSound.color2(156);
	//but_saveSound.color(156);


	// slider volume
	Fl_Slider slider_volume(130, 50, 90, 15, "volume");
	slider_volume.type(FL_HOR_NICE_SLIDER);
	slider_volume.maximum(100);
	slider_volume.minimum(5);
	slider_volume.scrollvalue(100, 10, 0, 100);
	slider_volume.callback(but_volume_set_cb, &slider_volume);
	slider_volume.color(156);
	slider_volume.color2(2); //GREEN

	Fl_Button but_speedMinus(230, 50, 30, 30, "@<<");
	but_speedMinus.shortcut('z');
	but_speedMinus.callback(but_speedMinus_cb);
	but_speedMinus.color2(Fl_Color(157));
	but_speedMinus.color(Fl_Color(157));

	Fl_Button but_speedPlus(275, 50, 30, 30, "@>>");
	but_speedPlus.shortcut('x');
	but_speedPlus.callback(but_speedPlus_cb);
	but_speedPlus.color2(Fl_Color(157));
	but_speedPlus.color(Fl_Color(157));

	Fl_Button but_exit(320, 50, 50, 30, "Exit");
	but_exit.shortcut(FL_Escape);
	but_exit.callback(but_exit_cb, &win);
	but_exit.color2(Fl_Color(157));
	but_exit.color(Fl_Color(157));


	Fl_Button but_play(50, 90, 30, 30, "@>");
	but_play.shortcut('s');
	but_play.callback(but_play_cb);
	but_play.color(Fl_Color(157));
	but_play.color2(Fl_Color(157));

	Fl_Button but_pause(10, 90, 30, 30, "||");
	but_pause.shortcut('p');
	but_pause.callback(but_pause_cb);
	but_pause.color2(Fl_Color(157));
	but_pause.color(Fl_Color(157));

	Fl_Light_Button but_loop(90, 90, 30, 30, "@refresh");
	but_loop.shortcut('i');
	but_loop.callback(but_loop_cb);
	but_loop.color2(Fl_Color(171));
	but_loop.color(Fl_Color(157));

	Fl_Button but_stop(50, 130, 30, 30, "@square");
	but_stop.shortcut('o');
	but_stop.callback(but_stop_cb);
	but_stop.color2(Fl_Color(157));
	but_stop.color(Fl_Color(157));

	Fl_Button but_rewind(10, 130, 30, 30, "@|<");
	but_rewind.shortcut('a');
	but_rewind.callback(but_rewind_cb);
	but_rewind.color2(Fl_Color(157));
	but_rewind.color(Fl_Color(157));

	Fl_Button but_forward(90, 130, 30, 30, "@>|");
	but_forward.shortcut('d');
	but_forward.callback(but_forward_cb);
	but_forward.color2(Fl_Color(157));
	but_forward.color(Fl_Color(157));


	// Effects Buttons

	Fl_Check_Button but_echo(230, 100, 100, 30, "Echo");
	but_echo.callback(but_echo_cb, &music);
	but_echo.color2(Fl_Color(58));
	but_echo.color(Fl_Color(157));

	// Sliders for effects
	//Echo
	Fl_Value_Slider slider_echo_force(230, 130, 140, 15, "Force [%]");
	slider_echo_force.type(FL_HOR_NICE_SLIDER);
	slider_echo_force.maximum(200);
	slider_echo_force.minimum(5);
	slider_echo_force.scrollvalue(100, 1, 0, 200);
	//slider_echo_force.callback(but_echo_force_set_cb, &slider_echo_force);
	slider_echo_force.color(156);
	slider_echo_force.color2(2); //GREEN


	// Sliders for effects
	Fl_Value_Slider slider_echo_delay(230, 170, 140, 15, "Delay [ms]");
	slider_echo_delay.type(FL_HOR_NICE_SLIDER);
	slider_echo_delay.maximum(5000);
	slider_echo_delay.minimum(10);
	slider_echo_delay.scrollvalue(100, 10, 0, 5000);
	//slider_echo_delay.callback(but_echo_delay_set_cb, &slider_echo_delay);
	slider_echo_delay.color(156);
	slider_echo_delay.color2(2); //GREEN

	// Distortion
	Fl_Check_Button but_distortion(230, 230, 100, 30, "Distortion");
	//but_loop.callback(but_loop_cb);
	but_distortion.color2(Fl_Color(58));
	but_distortion.color(Fl_Color(157));

	Fl_Value_Slider slider_distortion(230, 260, 140, 15, "Level of amplitude");
	slider_distortion.type(FL_HOR_NICE_SLIDER);
	slider_distortion.maximum(100);
	slider_distortion.minimum(5);
	slider_distortion.scrollvalue(100, 10, 0, 100);
	//slider_distortion.callback(but_volume_set_cb, &slider_distortion);
	slider_distortion.color(156);
	slider_distortion.color2(2); //GREEN

	//Wah-Wah
	Fl_Check_Button but_wah_wah(230, 310, 100, 30, "Wah-Wah");
	//but_loop.callback(but_loop_cb);
	but_wah_wah.color2(Fl_Color(58));
	but_wah_wah.color(Fl_Color(157));

	Fl_Value_Slider slider_wah_wah(230, 340, 140, 15, "Wah-Wah");
	slider_wah_wah.type(FL_HOR_NICE_SLIDER);
	slider_wah_wah.maximum(100);
	slider_wah_wah.minimum(5);
	slider_wah_wah.scrollvalue(100, 10, 0, 100);
	//slider_wah_wah.callback(but_volume_set_cb, &slider_wah_wah);
	slider_wah_wah.color(156);
	slider_wah_wah.color2(2); //GREEN



	win.end();
	win.show();
	return(Fl::run());

	//system("Pause");
	//return 0;
}





//########################## Stworzenie kopii oryginalu, modyfikacje, efekty #####################

//music.loadSound();
//std::vector<sf::Int16> effectSamples = music.getSamples();
//Echo echo1;
//echo1.setEcho(effectSamples);
//music.loadSamples(effectSamples, music.fs);



//########################## generowanie sampli, odtworzenie dzwieku z sampli #####################

//std::vector<sf::Int16> samples_gen;
//for (int t = 0; t < 200; t++)
//{
//	for (int f = 20; f < 16000; f += 20)
//	{
//		samples_gen.push_back(5000 * sin(2 * 3.14 * f * t));
//	}
//}
//
//for (int t = 200; t > 500; t++)
//{
//	for (int f = 16000; f > 20; f -= 20)
//	{
//		samples_gen.push_back(5000 * sin(2 * 3.14 * f * t));
//	}
//}

//int fs = 44100;
//
////const std::vector<sf::Int16> samples1 = samples;
//sf::SoundBuffer bufg;
//
//bufg.loadFromSamples(samples_gen.data(), samples_gen.size(), 1, fs);
//bufg.saveToFile("generate1.wav");
//
//sf::Sound soundG;
//soundG.setBuffer(bufg);
//soundG.play();

//odtworzenie przy pomocy bufora na gorze, oraz przy pomocy wczytania sampli na dole

//music.loadSamples(samples_gen, fs);
//music.playSoud();
//music.loopSound();


//############## modyfikacja sampli w pliku *wav ##################
/*
			sf::Sound soundM;
		sf::SoundBuffer bufM; //modified
		if (!bufM.loadFromFile("E:\\AGH\\Semestr 4\\PO\\Projekty\\Projekt-Efekt-Gitarowy\\Projekt-Efekt-Gitarowy\\generate1.wav"))
		{
			std::cout << "Cannot open file *.wav!!" << std::endl;
		}
		else
		{
			std::cout << "Open *.wav" << std::endl;
		}
		//soundM.setBuffer(bufM);
		//soundM.play();



		const::sf::Int16 *sample = bufM.getSamples();


		//for (int i = 0; i < buf1.getSampleCount(); i++)
		std::vector<sf::Int16> Dsamples;

			//Dsamples.push_back(*sample);

		//buf1.saveToFile("test.wav");
			for (int i = 0; i < bufM.getSampleCount(); i++)
			{
				Dsamples.push_back(*sample++);
				//std::cout << "Sample number:" << i << "is:   \t" << *sample++ << std::endl;
			}

			//music.loadSamples(Dsamples, fs);
			//music.playSoud();

			// ################## Poprawnie wczytano sample z vectora!! Hurrrrraaaaaa!! :D ##############
			// Teraz mozna modyfikwoac sample w wektorze, dodawac efekty itd.

			*/


			// echo efekt



			/*music.loadSound();
			std::vector<sf::Int16> Dsamples;
			Dsamples = music.getSamples();

			int start = 0;
			int delay = 3000;
			//int length = 500000;
			sf::Uint64 length = music.getLength();
			float echo_force = 1.5;


			std::vector<sf::Int16> delayedSamples;
			for (start; start < length; start++)
			{
				delayedSamples.push_back(Dsamples.at(start));
				//Dsamples.at(i + delay) = Dsamples.at(i) + delayedSamples.at(i);
			}

			for (int i = 0; i < delayedSamples.size() - delay; i++)
			{
				//delayedSamples.push_back(Dsamples.at(i));
				Dsamples.at(i + delay) = Dsamples.at(i + delay) + echo_force*delayedSamples.at(i);
			}
			music.loadSamples(Dsamples, fs);
			*/

			//music.playSoud();



		//bufx.loadFromSamples(Dsamples.data(), Dsamples.size(), 1, fx);
		//bufx.saveToFile("generate.wav");

		//music.loadSamples(Dsamples, 44100);

		//music.playSoud();

//sf::Sound sound1;
//sound1.setBuffer(buf1);
//sound1.play();

//sf::Music sound2;
//sound2.openFromFile("test.wav");
//sound2.play();



