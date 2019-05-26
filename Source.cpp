#define _CRT_SECURE_NO_DEPRECATE // odczyt fstream , 


#include "headers.h"
//#include "buttons_callback.h"


using namespace std;
using std::string;
using std::fstream;

typedef struct  WAV_HEADER {
	char                RIFF[4];        // RIFF Header      Magic header
	unsigned long       ChunkSize;      // RIFF Chunk Size  
	char                WAVE[4];        // WAVE Header      
	char                fmt[4];         // FMT header       
	unsigned long       Subchunk1Size;  // Size of the fmt chunk                                
	unsigned short      AudioFormat;    // Audio format 1=PCM,6=mulaw,7=alaw, 257=IBM Mu-Law, 258=IBM A-Law, 259=ADPCM 
	unsigned short      NumOfChan;      // Number of channels 1=Mono 2=Sterio                   
	unsigned long       SamplesPerSec;  // Sampling Frequency in Hz                             
	unsigned long       bytesPerSec;    // bytes per second 
	unsigned short      blockAlign;     // 2=16-bit mono, 4=16-bit stereo 
	unsigned short      bitsPerSample;  // Number of bits per sample      
	char                Subchunk2ID[4]; // "data"  string   
	unsigned long       Subchunk2Size;  // Sampled data length    

}wav_hdr;

// Function prototypes 
int getFileSize(FILE *inFile);


//ReadRIFF();
//ReadFMT();
//int32 chunk2Id = Read32(BigEndian);
//int32 chunk2Size = Read32(LittleEndian);






Music music;

void but_loadSound_cb(Fl_Widget* w, void*v)
{
	//((Fl_Window*)v)->hide()
	music.loadSound();
	std::cout << std::endl << "Button loadSound callback!" << std::endl;
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
	//((Fl_Window*)v)->hide()
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

// ########################################
// CLOSE WINDOW


void but_exit_cb(Fl_Widget *w, void* v)
{
	if (fl_ask("Do you want to exit?"))
	{
		((Fl_Window*)v)->hide();//zamkniecie okna glownego win, przy pomocy wskaznika
	}

	//Fl_Window exit_window(200, 90,"Exit");

	//
	//Fl_Box text(40,10,130,30,"Are you sure to exit?");

	//exit_window.color(9);
	//exit_window.begin();

	////MyButton but_yes(50, 40, 40, 30, "Yes");
	//Fl_Button but_yes(50, 40, 40, 30, "Yes");
	//but_yes.shortcut('y');
	//but_yes.callback(but_yes_cb);
	//but_yes.color2(Fl_Color(130));
	//but_yes.color(Fl_Color(130));

	//Fl_Button but_no(110, 40, 40, 30, "No");
	//but_no.shortcut('n');
	//but_no.callback(but_no_cb); // to correct! to fix!
	//but_no.color2(Fl_Color(157));
	//but_no.color(Fl_Color(157));
	//if (Fl::event_button() == true)
	//{
	//	if (FL_KEYDOWN == 'n') //Fl::get_key(FL_KEYBOARD) == 
	//	{
	//		exit(1);
	//	}
	//}


	//exit_window.end();
	//exit_window.show();

	//	Fl::run();
	//exit(0);
}


void but_yes_cb(Fl_Widget* w, void* v)
{
	std::cout << std::endl << "Button YES callback!" << std::endl;
}

void but_no_cb(Fl_Widget *w, void* v)
{
	std::cout << std::endl << "Button NO callback!" << std::endl;
}


int main()
{
	system("Color 0B");
	std::cout << "Efekt gitarowy - projekt" << std::endl;


	Fl_Window win(400, 200);
	win.color(148);
	win.begin();

	Fl_Button but_loadSound(10, 10, 110, 30, "@filenew Load Sound");
	but_loadSound.shortcut('l');
	but_loadSound.callback(but_loadSound_cb,&music);
	but_loadSound.color2(156);
	but_loadSound.color(156);


	// slider volume
	Fl_Slider slider_volume(130, 10, 90, 15, "volume");
	slider_volume.type(FL_HOR_NICE_SLIDER);
	slider_volume.maximum(100);
	slider_volume.minimum(5);
	slider_volume.scrollvalue(100, 10, 0, 100);
	slider_volume.callback(but_volume_set_cb,&slider_volume);
	slider_volume.color(156);
	slider_volume.color2(2); //GREEN
	

	//Fl_Button but_volumePlus(170, 10, 30, 30, "+");
	//but_volumePlus.callback(but_volumePlus_cb);

	//Fl_Button but_volumeMinus(130, 10, 30, 30, "-");
	//but_volumeMinus.callback(but_volumeMinus_cb);
	//

	Fl_Button but_speedMinus(230, 10, 30, 30, "@<<");
	but_speedMinus.shortcut('z');
	but_speedMinus.callback(but_speedMinus_cb);
	but_speedMinus.color2(Fl_Color(157));
	but_speedMinus.color(Fl_Color(157));

	Fl_Button but_speedPlus(275, 10, 30, 30, "@>>");
	but_speedPlus.shortcut('x');
	but_speedPlus.callback(but_speedPlus_cb);
	but_speedPlus.color2(Fl_Color(157));
	but_speedPlus.color(Fl_Color(157));

	Fl_Button but_exit(320, 10, 50, 30, "Exit");
	but_exit.shortcut(FL_Escape); 
	but_exit.callback(but_exit_cb,&win);
	but_exit.color2(Fl_Color(157));
	but_exit.color(Fl_Color(157));


	Fl_Button but_play(50, 50, 30, 30, "@>");
	but_play.shortcut('s');
	but_play.callback(but_play_cb);
	but_play.color(Fl_Color(157));
	but_play.color2(Fl_Color(157));

	Fl_Button but_pause(10, 50, 30, 30,"||");
	but_pause.shortcut('p');
	but_pause.callback(but_pause_cb);
	but_pause.color2(Fl_Color(157));
	but_pause.color(Fl_Color(157));
	
	Fl_Light_Button but_loop(90, 50, 30, 30, "@refresh");
	but_loop.shortcut('i');
	but_loop.callback(but_loop_cb);
	but_loop.color2(Fl_Color(171));
	but_loop.color(Fl_Color(157));
	
	Fl_Button but_stop(50, 90, 30, 30, "@square");
	but_stop.shortcut('o');
	but_stop.callback(but_stop_cb);
	but_stop.color2(Fl_Color(157));
	but_stop.color(Fl_Color(157));

	Fl_Button but_rewind(10, 90, 30, 30, "@|<");
	but_rewind.shortcut('a');
	but_rewind.callback(but_rewind_cb);
	but_rewind.color2(Fl_Color(157));
	but_rewind.color(Fl_Color(157));

	Fl_Button but_forward(90, 90, 30, 30, "@>|");
	but_forward.shortcut('d');
	but_forward.callback(but_forward_cb);
	but_forward.color2(Fl_Color(157));
	but_forward.color(Fl_Color(157));
	
	win.end();
	win.show();


	
		std::vector<sf::Int16> samples;
		for (int t = 0; t < 200; t++)
		{
			for (int f = 20; f < 16000; f+=20)
			{
				samples.push_back(5000 * sin(2 * 3.14 * f * t));
			}
		}

		for (int t = 200; t > 500; t++)
		{
			for (int f = 16000; f >20; f-20)
			{
				samples.push_back(5000 * sin(2 * 3.14 * f * t));
			}
		}

		
		music.loadSamples(samples, 44100);
		
		
		music.playSoud();
		//music.loopSound();


		sf::SoundBuffer buf1;
		buf1.loadFromFile("E:\\AGH\\Semestr 4\\PO\\Projekty\\Projekt-Efekt-Gitarowy\\imperial_march.wav");
	
		buf1.getSamples();

		buf1.saveToFile("test.wav");
		sf::Sound sound1;
		//sound1.setBuffer(buf1);
		//sound1.play();

		sf::Music sound2;
		sound2.openFromFile("test.wav");
		sound2.play();

	//to do:
		//funkcja do zapisywania sampli, 
		//inna funkcja odczyta sample do wektora, modyfikacja, dodanie echa, inne efekty,
		//odtworzenie
	/*



		wav_hdr wavHeader;
		FILE *wavFile;
		int headerSize = sizeof(wav_hdr), filelength = 0;

		string answer;

		do {
			string input;
			string answer;

			const char* filePath;

			cout << "Pick wav file from the Windows Media File: ";
			//cin >> input;
			//cin.get();

			cout << endl;

			std::string path = "E:\\AGH\\Semestr 4\\PO\\Projekty\\Projekt-Efekt-Gitarowy\\imperial_march.wav";
			filePath = path.c_str();

			wavFile = fopen("E:\\AGH\\Semestr 4\\PO\\Projekty\\Projekt-Efekt-Gitarowy\\imperial_march.wav","r");

			if (wavFile == NULL) {
				printf("Can not able to open wave file\n");
				//exit(EXIT_FAILURE);
			}

			fread(&wavHeader, headerSize, 1, wavFile);
			filelength = getFileSize(wavFile);
			fclose(wavFile);

			cout << "File is                    :" << filelength << " bytes." << endl;

			cout << "RIFF header                :" << wavHeader.RIFF[0]
				<< wavHeader.RIFF[1]
				<< wavHeader.RIFF[2]
				<< wavHeader.RIFF[3] << endl;

			cout << "WAVE header                :" << wavHeader.WAVE[0]
				<< wavHeader.WAVE[1]
				<< wavHeader.WAVE[2]
				<< wavHeader.WAVE[3]
				<< endl;

			cout << "FMT                        :" << wavHeader.fmt[0]
				<< wavHeader.fmt[1]
				<< wavHeader.fmt[2]
				<< wavHeader.fmt[3]
				<< endl;

			cout << "Data size                  :" << wavHeader.ChunkSize << endl;

			// Display the sampling Rate form the header
			cout << "Sampling Rate              :" << wavHeader.SamplesPerSec << endl;
			cout << "Number of bits used        :" << wavHeader.bitsPerSample << endl;
			cout << "Number of channels         :" << wavHeader.NumOfChan << endl;
			cout << "Number of bytes per second :" << wavHeader.bytesPerSec << endl;
			cout << "Data length                :" << wavHeader.Subchunk2Size << endl;
			cout << "Audio Format               :" << wavHeader.AudioFormat << endl;
			// Audio format 1=PCM,6=mulaw,7=alaw, 257=IBM Mu-Law, 258=IBM A-Law, 259=ADPCM 


			cout << "Block align                :" << wavHeader.blockAlign << endl;

			cout << "Data string                :" << wavHeader.Subchunk2ID[0]
				<< wavHeader.Subchunk2ID[1]
				<< wavHeader.Subchunk2ID[2]
				<< wavHeader.Subchunk2ID[3]
				<< endl;

			cout << endl << endl << "Try something else? (y/n)";
			cin >> answer;
			cin.get();
			cout << endl << endl;

		


		} while (answer == "y");


		getchar();

		*/
	//system("Pause");  
	return(Fl::run());
	//return 0;
}

// find the file size 
int getFileSize(FILE *inFile) {
	int fileSize = 0;
	fseek(inFile, 0, SEEK_END);

	fileSize = ftell(inFile);

	fseek(inFile, 0, SEEK_SET);
	return fileSize;
}



//////////class MyButton : public Fl_Button
//////////{
//////////	static int count;
//////////public:
//////////	MyButton(int x, int y, int w, int h, const char*l = 0)
//////////		:Fl_Button(x, y, w, h, l) {}
//////////
//////////	int handle(int e)
//////////	{
//////////		int ret = Fl_Button::handle(e);
//////////		cout << endl << count++ << " ******** button " << label() << " receives ";
//////////
//////////
//////////		switch (e)
//////////		{
//////////		case FL_PUSH:
//////////			cout << "push" << " event and returns:" << ret << endl;
//////////			break;
//////////
//////////		case FL_RELEASE:
//////////			cout << "release" << " event and returns:" << ret << endl;
//////////			break;
//////////
//////////		case FL_ENTER:
//////////			color(FL_CYAN);
//////////			cout << "enter" << " event and returns:" << ret << endl;
//////////			redraw();
//////////			break;
//////////
//////////		case FL_LEAVE:
//////////			color(FL_BACKGROUND_COLOR);
//////////			cout << "leave" << " event and returns:" << ret << endl;
//////////			redraw();
//////////			break;
//////////
//////////		case FL_DRAG:
//////////			cout << "drag" << " event and returns:" << ret << endl;
//////////			break;
//////////
//////////		case FL_FOCUS:
//////////			cout << "focus" << " event and returns:" << ret << endl;
//////////			break;
//////////
//////////		case FL_UNFOCUS:
//////////			cout << "unfocus" << " event and returns:" << ret << endl;
//////////			break;
//////////
//////////		case FL_KEYDOWN:
//////////			cout << "keydown" << " event and returns:" << ret << endl;
//////////			break;
//////////
//////////		case FL_KEYUP:
//////////			if (Fl::event_key() == shortcut()) {
//////////				box(FL_UP_BOX);
//////////				redraw();
//////////				ret = 1; //return handled so keyup event stops
//////////			}         //being sent to ALL other buttons unecessarily
//////////
//////////			cout << "keyup" << " event and returns:" << ret << endl;
//////////			break;
//////////
//////////		case FL_CLOSE:
//////////			cout << "close" << " event and returns:" << ret << endl;
//////////			break;
//////////
//////////		case FL_MOVE:
//////////			cout << "move" << " event and returns:" << ret << endl;
//////////			break;
//////////
//////////		case FL_SHORTCUT:
//////////			if (Fl::event_key() == shortcut()) {
//////////				box(FL_DOWN_BOX);
//////////				redraw();
//////////			}
//////////			cout << "shortcut" << " event and returns:" << ret << endl;
//////////			break;
//////////
//////////		case FL_DEACTIVATE:
//////////			cout << "deactivate" << " event and returns:" << ret << endl;
//////////			break;
//////////
//////////		case FL_ACTIVATE:
//////////			cout << "activate" << " event and returns:" << ret << endl;
//////////			break;
//////////
//////////		case FL_HIDE:
//////////			cout << "hide" << " event and returns:" << ret << endl;
//////////			break;
//////////
//////////		case FL_SHOW:
//////////			cout << "show" << " event and returns:" << ret << endl;
//////////			break;
//////////
//////////		case FL_PASTE:
//////////			cout << "paste" << " event and returns:" << ret << endl;
//////////			break;
//////////
//////////		case  FL_SELECTIONCLEAR:
//////////			cout << "selectionclear" << " event and returns:" << ret << endl;
//////////			break;
//////////
//////////		case  FL_MOUSEWHEEL:
//////////			cout << "mousewheel" << " event and returns:" << ret << endl;
//////////			break;
//////////
//////////		case  FL_NO_EVENT:
//////////			cout << "no event" << " and returns:" << ret << endl;
//////////			break;
//////////
//////////
//////////
//////////		}
//////////		return(ret);
//////////	}
//////////
//////////};
//////////
//////////
//////////int MyButton::count = 0;