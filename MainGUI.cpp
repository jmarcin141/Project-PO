#include "headers.h"
#include "buttons_callback.h"
#include "GlobalVariables.h"




int main()
{
	system("Color 0B");
	std::cout << "Efekt gitarowy - projekt\n Author: Jakub Marcinkowski, Krakow, 06.2019\n\n" << std::endl;

	int ret = initGUI(music, oryginalMusic, effectsMusic, loadedFiles);	
return ret;
}











//########################################
//DEFINITIONS OF FUNCTIONS
int initGUI(Music &mMusic, Music &mOryginal, Music &mEffectsMusic, bool openedFiles)
{

	Fl_Window win(800, 480);
	win.color(148);
	win.begin();

	

	Fl_Text_Display soundLengthText(210, 130, 0, 30, "Music length: --:--:--");
	soundLengthText.align(FL_ALIGN_RIGHT);
	boxesWidget.push_back(&soundLengthText);

	Fl_Text_Display availableSoundsLabel(5, 25, 165, 445, "My music folder:");

	Fl_Text_Display effectsSoundLabel1(433, 170, 227, 300, ""); // vertical
	Fl_Text_Display effectsSoundLabel2(210, 290, 450, 180, ""); //horizontal up
	Fl_Text_Display effectsSoundLabel3(210, 380, 450, 90, ""); //horizontal down
	Fl_Text_Display effectsSoundLabel(210, 170, 450, 300, "Effects:");


	Fl_Box availableSounds(15, 30, 0, 380, "example_track.wav");
	availableSounds.align(FL_ALIGN_RIGHT_TOP);
	availableSounds.color2(148);
	availableSounds.color(156);
	printMusicList(&availableSounds); 


	Fl_Input fileName(310, 10, 100, 30, "@fileopen Load Sound");
	fileName.callback(but_loadSound_cb, &fileName);
	fileName.color2(148);
	fileName.color(156);

	Fl_Input fileSaveName(560, 10, 100, 30, "@filesave Save Sound");
	fileSaveName.callback(but_saveSound_cb, &fileSaveName);
	fileSaveName.color2(148);
	fileSaveName.color(156);

	Fl_Button but_loadSoundAccept(410, 10, 30, 30, "@search");
	but_loadSoundAccept.shortcut(FL_Enter);
	but_loadSoundAccept.color2(156);
	but_loadSoundAccept.color(156);

	Fl_Button but_changeSound(340, 60, 130, 30, "Original");
	but_changeSound.shortcut(FL_Caps_Lock);
	but_changeSound.callback(&but_changeSound_cb);
	but_changeSound.color2(156);
	but_changeSound.color(156);


	Fl_Button but_resetEffects(340, 100, 130, 30, "Reset Effects");
	but_resetEffects.shortcut('r');
	but_resetEffects.callback(but_resetEffects_cb);
	but_resetEffects.color2(156);
	but_resetEffects.color(156);


	// slider volume
	Fl_Slider slider_volume(490, 62, 170, 15, "volume");
	slider_volume.type(FL_HOR_NICE_SLIDER);
	slider_volume.maximum(100);
	slider_volume.minimum(5);
	slider_volume.scrollvalue(100, 10, 0, 100);
	slider_volume.callback(but_volume_set_cb, &slider_volume);
	slider_volume.color(156);
	slider_volume.color2(2); //GREEN


	Fl_Button but_speedMinus(490, 100, 30, 30, "@<<");
	but_speedMinus.shortcut(FL_F + 9);
	but_speedMinus.callback(but_speedMinus_cb, &mMusic);
	but_speedMinus.color2(Fl_Color(157));
	but_speedMinus.color(Fl_Color(157));

	Fl_Button but_speedPlus(530, 100, 30, 30, "@>>");
	but_speedPlus.shortcut(FL_F + 11);
	but_speedPlus.callback(but_speedPlus_cb, &mMusic);
	but_speedPlus.color2(Fl_Color(157));
	but_speedPlus.color(Fl_Color(157));

	Fl_Button but_exit(575, 100, 85, 30, "Exit");
	but_exit.shortcut(FL_Escape);
	but_exit.callback(but_exit_cb, &win);
	but_exit.color2(Fl_Color(157));
	but_exit.color(Fl_Color(157));

	
	Fl_Button but_play(250, 60, 30, 30, "@>");
	but_play.shortcut('/');
	but_play.callback(but_play_cb, &mMusic);
	but_play.color(Fl_Color(157));
	but_play.color2(Fl_Color(157));
	
	Fl_Button but_pause(210, 60, 30, 30, "||");
	but_pause.shortcut(FL_Pause);
	but_pause.callback(but_pause_cb, &mMusic);
	but_pause.color2(Fl_Color(157));
	but_pause.color(Fl_Color(157));

	Fl_Light_Button but_loop(290, 60, 30, 30, "@refresh");
	but_loop.shortcut('i');
	but_loop.callback(but_loop_cb, &mMusic);
	but_loop.color2(Fl_Color(171));
	but_loop.color(Fl_Color(157));

	Fl_Button but_stop(250, 100, 30, 30, "@square");
	but_stop.shortcut(FL_F + 10);
	but_stop.callback(but_stop_cb, &mMusic);
	but_stop.color2(Fl_Color(157));
	but_stop.color(Fl_Color(157));

	Fl_Button but_rewind(210, 100, 30, 30, "@|<");
	but_rewind.shortcut('a');
	but_rewind.callback(but_rewind_cb, &mMusic);
	but_rewind.color2(Fl_Color(157));
	but_rewind.color(Fl_Color(157));

	Fl_Button but_forward(290, 100, 30, 30, "@>|");
	but_forward.shortcut('d');
	but_forward.callback(but_forward_cb, &mMusic);
	but_forward.color2(Fl_Color(157));
	but_forward.color(Fl_Color(157));


	// Effects Buttons

	// Reverse samples
	Fl_Check_Button but_reverse(230, 400, 180, 30, "Reverse samples");
	but_reverse.callback(but_reverse_cb, &mEffectsMusic);
	but_reverse.color2(Fl_Color(58));
	but_reverse.color(Fl_Color(157));
	but_reverse.type(FL_NORMAL_BUTTON);

	//Echo
	Fl_Check_Button but_echo(230, 180, 180, 30, "Echo");
	but_echo.callback(but_echo_cb, &mEffectsMusic);
	but_echo.color2(Fl_Color(58));
	but_echo.color(Fl_Color(157));
	but_echo.type(FL_NORMAL_BUTTON);

	// Sliders for effects
	//Echo
	Fl_Value_Slider slider_echo_force(230, 210, 180, 15, "Force [%]");
	slider_echo_force.type(FL_HOR_NICE_SLIDER);
	slider_echo_force.maximum(100);
	slider_echo_force.minimum(5);
	slider_echo_force.scrollvalue(50, 1, 0, 101);
	slider_echo_force.callback(but_echo_force_set_cb, &slider_echo_force);
	slider_echo_force.color(156);
	slider_echo_force.color2(2); //GREEN

	// Sliders for effects
	Fl_Value_Slider slider_echo_delay(230, 250, 180, 15, "Delay [ms]");
	slider_echo_delay.type(FL_HOR_NICE_SLIDER);
	slider_echo_delay.maximum(1000);
	slider_echo_delay.minimum(10);
	slider_echo_delay.scrollvalue(300, 1, 0, 1001);
	slider_echo_delay.callback(but_echo_delay_set_cb, &slider_echo_delay);
	slider_echo_delay.color(156);
	slider_echo_delay.color2(2); //GREEN

	// Distortion
	Fl_Check_Button but_distortion(230, 310, 180, 30, "Distortion");
	but_distortion.callback(but_distortion_cb, &mEffectsMusic);
	but_distortion.color2(Fl_Color(58));
	but_distortion.color(Fl_Color(157));
	but_distortion.type(FL_NORMAL_BUTTON);

	Fl_Value_Slider slider_distortion(230, 340, 180, 15, "Level of amplitude [%]");
	slider_distortion.type(FL_HOR_NICE_SLIDER);
	slider_distortion.maximum(100);
	slider_distortion.minimum(5);
	slider_distortion.scrollvalue(50, 1, 0, 101);
	slider_distortion.callback(but_distortion_set_cb, &slider_distortion);
	slider_distortion.color(156);
	slider_distortion.color2(2); //GREEN

	// Bit Crusher
	Fl_Check_Button but_bitCrusher(460, 310, 180, 30, "Bit Crusher");
	but_bitCrusher.callback(but_bitCrusher_cb, &mEffectsMusic);
	but_bitCrusher.color2(Fl_Color(58));
	but_bitCrusher.color(Fl_Color(157));
	but_bitCrusher.type(FL_NORMAL_BUTTON);

	Fl_Value_Slider slider_bitCrusher(460, 340, 180, 15, "Reduce resolution by");
	slider_bitCrusher.type(FL_HOR_NICE_SLIDER);
	slider_bitCrusher.maximum(10);
	slider_bitCrusher.minimum(2);
	slider_bitCrusher.scrollvalue(2, 2, 2, 10);
	slider_bitCrusher.callback(but_bitCrusher_set_cb, &slider_bitCrusher);
	slider_bitCrusher.color(156);
	slider_bitCrusher.color2(2); //GREEN

	//Ring Modulator
	Fl_Check_Button but_ringModulator(460, 180, 180, 30, "Ring Modulator");
	but_ringModulator.callback(but_ringModulator_cb, &mEffectsMusic);
	but_ringModulator.color2(Fl_Color(58));
	but_ringModulator.color(Fl_Color(157));
	but_ringModulator.type(FL_NORMAL_BUTTON);

	Fl_Value_Slider slider_ringModulator_force(460, 210, 180, 15, "Force [%]");
	slider_ringModulator_force.type(FL_HOR_NICE_SLIDER);
	slider_ringModulator_force.maximum(100);
	slider_ringModulator_force.minimum(5);
	slider_ringModulator_force.scrollvalue(50, 1, 0, 101);
	slider_ringModulator_force.callback(but_ringModulatorForce_set_cb, &slider_ringModulator_force);
	slider_ringModulator_force.color(156);
	slider_ringModulator_force.color2(2); //GREEN

	Fl_Value_Slider slider_ringModulator_freq(460, 250, 180, 15, "Frequency [Hz]");
	slider_ringModulator_freq.type(FL_HOR_NICE_SLIDER);
	slider_ringModulator_freq.maximum(1000);
	slider_ringModulator_freq.minimum(20);
	slider_ringModulator_freq.scrollvalue(500, 1, 20, 1001);
	slider_ringModulator_freq.callback(but_ringModulatorFreq_set_cb, &slider_ringModulator_freq);
	slider_ringModulator_freq.color(156);
	slider_ringModulator_freq.color2(2); //GREEN

	//Wah-Wah
	Fl_Check_Button but_tremolo(460, 390, 180, 30, "Tremolo");
	but_tremolo.callback(but_tremolo_cb, &mEffectsMusic);
	but_tremolo.color2(Fl_Color(58));
	but_tremolo.color(Fl_Color(157));
	but_tremolo.type(FL_NORMAL_BUTTON);

	Fl_Value_Slider slider_tremolo(460, 420, 180, 15, "Frequency[Hz]");
	slider_tremolo.type(FL_HOR_NICE_SLIDER);
	slider_tremolo.maximum(1000);
	slider_tremolo.minimum(5);
	slider_tremolo.scrollvalue(200, 1, 20, 981);
	slider_tremolo.callback(but_tremolo_set_cb, &slider_tremolo);
	slider_tremolo.color(156);
	slider_tremolo.color2(2); //GREEN


	//do wektora daje referencje do widgetow, ktore nalezy wyszarzyc !!
	//std::vector <Fl_Widget*> widgetsPtr;
	widgetsPtr.push_back(&fileSaveName);
	widgetsPtr.push_back(&effectsSoundLabel);
	widgetsPtr.push_back(&effectsSoundLabel1);
	widgetsPtr.push_back(&effectsSoundLabel2);
	widgetsPtr.push_back(&effectsSoundLabel3);
	widgetsPtr.push_back(&but_play);
	widgetsPtr.push_back(&but_changeSound);
	widgetsPtr.push_back(&but_pause);
	widgetsPtr.push_back(&but_loop);
	widgetsPtr.push_back(&but_stop);
	widgetsPtr.push_back(&but_rewind);
	widgetsPtr.push_back(&but_forward);
	widgetsPtr.push_back(&but_speedPlus);
	widgetsPtr.push_back(&but_speedMinus);
	widgetsPtr.push_back(&but_resetEffects);
	widgetsPtr.push_back(&but_echo);
	widgetsPtr.push_back(&slider_echo_delay);
	widgetsPtr.push_back(&slider_echo_force);
	widgetsPtr.push_back(&but_distortion);
	widgetsPtr.push_back(&slider_distortion);
	widgetsPtr.push_back(&but_bitCrusher);
	widgetsPtr.push_back(&slider_bitCrusher);
	widgetsPtr.push_back(&but_ringModulator);
	widgetsPtr.push_back(&slider_ringModulator_force);
	widgetsPtr.push_back(&slider_ringModulator_freq);
	widgetsPtr.push_back(&but_reverse);
	widgetsPtr.push_back(&but_tremolo);
	widgetsPtr.push_back(&slider_tremolo);
	widgetsPtr.push_back(&but_resetEffects);
	widgetsPtr.push_back(&slider_volume);
	widgetsPtr.push_back(&soundLengthText);

	//wyszarz
	deactivateAllWidgetsInVectorOfPointers(loadedFiles, widgetsPtr);


	win.end();
	win.show();
	return(Fl::run());
}


//definitions of functions for sound
void but_loadSound_cb(Fl_Widget* w, void* v)
{
	std::string name = ((Fl_Input*)v)->value();
	music.setFileName(name);
	loadedFiles = music.loadSound();

	oryginalMusic.setFileName(name);
	effectsMusic.setFileName(name);
	oryginalMusic.loadSound();
	effectsMusic.loadSound();
	music.setSpeed(1);

	deactivateAllWidgetsInVectorOfPointers(loadedFiles, widgetsPtr);
	printTimeMusic(boxesWidget, music.getLengthTime()); //boxPtr

	std::cout << std::endl << "Button loadSound callback!" << std::endl;
}

void but_saveSound_cb(Fl_Widget* w, void*v)
{
	std::string name = ((Fl_Input*)v)->value();
	////music.saveSound(name);
	effectsMusic.saveSound(name);
	std::cout << std::endl << "Button saveSound callback!" << std::endl;
}

//slider
void but_volume_set_cb(Fl_Widget *w, void *v)
{
	music.setVolume(((Fl_Value_Slider*)v)->value());
	effectsMusic.setVolume(((Fl_Value_Slider*)v)->value());
	oryginalMusic.setVolume(((Fl_Value_Slider*)v)->value());
}


void but_changeSound_cb(Fl_Widget *w, void* v)
{
	std::cout << std::endl << "Button change sound callback!" << std::endl;
	if (w->label() == "Original")
	{
		w->label("After effects");
		music = effectsMusic;
		////music.setSpeed(0.5f); // stereo channel , trzeba zmniejszyc odtwarrzanie fs
		std::cout << std::endl << "w->label() == Original" << std::endl;
	}
	else
	{
		w->label("Original");
		std::cout << std::endl << " w->label() == After effects " << std::endl;
		music = oryginalMusic;
		////music.setSpeed(1.f);
	}
}

void but_resetEffects_cb(Fl_Widget *w, void* v)
{
	effectsMusic.setFs(oryginalMusic.getFs());
	effectsMusic.loadSound();

	music.setSpeed(1);
	std::cout << std::endl << "Button reset effects callback!" << std::endl;
}



void but_echo_cb(Fl_Widget *w, void* v)
{
	std::vector<sf::Int16> samples = ((Music*)v)->getSamples();
	std::cout << std::endl << "Button echo callback!" << std::endl;
	echoEffect.effect(samples);

	if (effectsMusic.loadSamples(samples, effectsMusic.getFs()))
	{
		w->type(FL_NORMAL_BUTTON);
	}

}

void but_echo_force_set_cb(Fl_Widget *w, void* v)
{
	std::cout << std::endl << "Button echo force set callback!" << std::endl;
	echoEffect.setParamFloat1(static_cast<float>((((Fl_Value_Slider*)v)->value()) / 100)); // podzielic przez 100 % !
}

void but_echo_delay_set_cb(Fl_Widget *w, void* v)
{
	std::cout << std::endl << "Button echo delay set callback!" << std::endl;
	echoEffect.setParamInt1(static_cast<int>((((Fl_Value_Slider*)v)->value()*(effectsMusic.getFs() / 1000))));
}

void but_distortion_cb(Fl_Widget *w, void* v)
{
	std::cout << std::endl << "Button distortion callback!" << std::endl;
	std::vector<sf::Int16> samples = ((Music*)v)->getSamples();
	distortionEffect.effect(samples);
	if (effectsMusic.loadSamples(samples, effectsMusic.getFs()))
	{
		w->type(FL_NORMAL_BUTTON);
	}
}

void but_distortion_set_cb(Fl_Widget *w, void* v)
{
	std::cout << std::endl << "Button distortion set callback!" << std::endl;
	distortionEffect.setParamFloat1(static_cast<float>((((Fl_Value_Slider*)v)->value()) / 100));
}

void but_bitCrusher_cb(Fl_Widget *w, void* v)
{
	std::cout << std::endl << "Button bitCrusher callback!" << std::endl;
	std::vector<sf::Int16> samples = ((Music*)v)->getSamples();
	bitCrusherEffect.effect(samples);
	if (effectsMusic.loadSamples(samples, effectsMusic.getFs()))
	{
		w->type(FL_NORMAL_BUTTON);
	}
}

void but_bitCrusher_set_cb(Fl_Widget *w, void* v)
{
	std::cout << std::endl << "Button bitCrusher set callback!" << std::endl;
	bitCrusherEffect.setParamInt1(static_cast<int>(((Fl_Value_Slider*)v)->value()));
	effectsMusic.setFs(static_cast<int>(oryginalMusic.getFs()/(4*((Fl_Value_Slider*)v)->value()))); // 4 is a factor of density frequency
}


void but_ringModulator_cb(Fl_Widget *w, void* v)
{
	std::cout << std::endl << "Button ringModulator callback!" << std::endl;
	std::vector<sf::Int16> samples = ((Music*)v)->getSamples();
	ringModulatorEffect.effect(samples);
	if (effectsMusic.loadSamples(samples, effectsMusic.getFs()))
	{
		w->type(FL_NORMAL_BUTTON);
	}
}

void but_ringModulatorForce_set_cb(Fl_Widget *w, void* v)
{
	std::cout << std::endl << "Button ringModulator force set callback!" << std::endl;
	ringModulatorEffect.setParamFloat1(static_cast<float>((((Fl_Value_Slider*)v)->value()) / 100)); //[%]
}

void but_ringModulatorFreq_set_cb(Fl_Widget *w, void* v)
{
	std::cout << std::endl << "Button ringModulator freq set callback!" << std::endl;
	ringModulatorEffect.setParamInt1(static_cast<int>((((Fl_Value_Slider*)v)->value())));
}


void but_reverse_cb(Fl_Widget *w, void* v)
{
	std::cout << std::endl << "Button Reverse callback!" << std::endl;
	std::vector<sf::Int16> samples = ((Music*)v)->getSamples();
	reverseEffect.effect(samples);
	if (effectsMusic.loadSamples(samples, effectsMusic.getFs()))
	{
		w->type(FL_NORMAL_BUTTON);
	}
}


void but_tremolo_cb(Fl_Widget *w, void* v)
{
	std::cout << std::endl << "Button tremolo callback!" << std::endl;
	std::vector<sf::Int16> samples = ((Music*)v)->getSamples();
	tremoloEffect.effect(samples);
	if (effectsMusic.loadSamples(samples, effectsMusic.getFs()))
	{
		w->type(FL_NORMAL_BUTTON);
	}
}

void but_tremolo_set_cb(Fl_Widget *w, void* v)
{
	std::cout << std::endl << "Button tremolo set callback!" << std::endl;
	tremoloEffect.setParamInt1(static_cast<int>(((Fl_Value_Slider*)v)->value()));
}





// ONLY FOR DEVELOPERS

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



