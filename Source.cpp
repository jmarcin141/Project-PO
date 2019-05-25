//#include<FL/Fl.h>
//#include<FL/Fl_Box.h>
//#include<FL/Fl_Window.h>

//int main()
//{
//	Fl_Window window(200, 200, "Window title");
//	Fl_Box box(0, 0, 200, 200, "Hey, I mean, Hello, World!");
//	window.show();
//	return Fl::run();
//}






//#define _CRT_SECURE_NO_DEPRECATE // odczyt fstream , 
#include <iostream>
#include <string>
#include <fstream>
#include <memory>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>
//#include <FL/Fl_Text_Display.H>

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






class MyButton : public Fl_Button
{
	static int count;
public:
	MyButton(int x, int y, int w, int h, const char*l = 0)
		:Fl_Button(x, y, w, h, l) {}

	int handle(int e)
	{
		int ret = Fl_Button::handle(e);
		cout << endl << count++ << " ******** button " << label() << " receives ";


		switch (e)
		{
		case FL_PUSH:
			cout << "push" << " event and returns:" << ret << endl;
			break;

		case FL_RELEASE:
			cout << "release" << " event and returns:" << ret << endl;
			break;

		case FL_ENTER:
			color(FL_CYAN);
			cout << "enter" << " event and returns:" << ret << endl;
			redraw();
			break;

		case FL_LEAVE:
			color(FL_BACKGROUND_COLOR);
			cout << "leave" << " event and returns:" << ret << endl;
			redraw();
			break;

		case FL_DRAG:
			cout << "drag" << " event and returns:" << ret << endl;
			break;

		case FL_FOCUS:
			cout << "focus" << " event and returns:" << ret << endl;
			break;

		case FL_UNFOCUS:
			cout << "unfocus" << " event and returns:" << ret << endl;
			break;

		case FL_KEYDOWN:
			cout << "keydown" << " event and returns:" << ret << endl;
			break;

		case FL_KEYUP:
			if (Fl::event_key() == shortcut()) {
				box(FL_UP_BOX);
				redraw();
				ret = 1; //return handled so keyup event stops
			}         //being sent to ALL other buttons unecessarily

			cout << "keyup" << " event and returns:" << ret << endl;
			break;

		case FL_CLOSE:
			cout << "close" << " event and returns:" << ret << endl;
			break;

		case FL_MOVE:
			cout << "move" << " event and returns:" << ret << endl;
			break;

		case FL_SHORTCUT:
			if (Fl::event_key() == shortcut()) {
				box(FL_DOWN_BOX);
				redraw();
			}
			cout << "shortcut" << " event and returns:" << ret << endl;
			break;

		case FL_DEACTIVATE:
			cout << "deactivate" << " event and returns:" << ret << endl;
			break;

		case FL_ACTIVATE:
			cout << "activate" << " event and returns:" << ret << endl;
			break;

		case FL_HIDE:
			cout << "hide" << " event and returns:" << ret << endl;
			break;

		case FL_SHOW:
			cout << "show" << " event and returns:" << ret << endl;
			break;

		case FL_PASTE:
			cout << "paste" << " event and returns:" << ret << endl;
			break;

		case  FL_SELECTIONCLEAR:
			cout << "selectionclear" << " event and returns:" << ret << endl;
			break;

		case  FL_MOUSEWHEEL:
			cout << "mousewheel" << " event and returns:" << ret << endl;
			break;

		case  FL_NO_EVENT:
			cout << "no event" << " and returns:" << ret << endl;
			break;



		}
		return(ret);
	}

};




class Music
{
private:
	sf::SoundBuffer buf;
	sf::Sound sound;

public:
	Music() {}

	//~Music() {}

	void loadSound()
	{
		if (!buf.loadFromFile("E:\\AGH\\Semestr 4\\PO\\Projekty\\Projekt-Efekt-Gitarowy\\imperial_march.wav"))
		{
			std::cout << "not loaded" << std::endl;
			//return -1;
		}
		else { std::cout << "loaded" << std::endl; }
		sound.setBuffer(buf);
	}

	bool getActiveSound()
	{
		if (sf::Sound::Status::Playing )
		{
			return true;
		}
		else {
			return false;
		}
	}

	void playSoud()
	{
		sound.play();
	}

	void stopSound()
	{
		sound.stop();
	}

	void pauseSound()
	{
		sound.pause();
	}

	void loopSound()
	{
		if (sound.getLoop() == true) {
			sound.setLoop(false);
		}
		else { sound.setLoop(true); }
	}

	void rewindSound()
	{
		if (sound.getPlayingOffset() > sf::seconds(5) ) {
			sound.setPlayingOffset(sound.getPlayingOffset() - sf::seconds(5));
		}
		else { sound.setPlayingOffset(sf::seconds(0)); }
	}

	void forwardSound()
	{
		sound.setPlayingOffset(sf::seconds(5) + sound.getPlayingOffset());
	}

	void volumePlus()
	{
		//Volume is...(between 0 - 100);
		if (sound.getVolume() <= 100) {
			sound.setVolume(sound.getVolume() + 5);
		}
	}
	
	void volumeMinus()
	{
		//Volume is...(between 0 - 100);
		if (sound.getVolume() >= 5) {
			sound.setVolume(sound.getVolume() - 5);
		}
	}

	void speedPlus()
	{
		if (sound.getPitch() <= 2.f) {
			sound.setPitch(sound.getPitch() + 0.2f);
		} 
		else if (sound.getPitch() > 2.f && sound.getPitch() < 7.f) {
			sound.setPitch(sound.getPitch() + 1.f);
		}
		else { sound.setPitch(1.f); }
	}

	void speedMinus()
	{
		if (sound.getPitch() <= 2.f && sound.getPitch() > 0.3f ) {
			sound.setPitch(sound.getPitch() - 0.2f);
		}
		else if (sound.getPitch() > 2.f && sound.getPitch() < 7.f) {
			sound.setPitch(sound.getPitch() - 1.f);
		}
	}
};


int MyButton::count = 0;

Music music;

void but_loadSound_cb(Fl_Widget* w, void*v) 
{
	music.loadSound();
	std::cout << std::endl << "Button loadSound callback!" << std::endl;
}

void but_play_cb(Fl_Widget* w, void* v)
{
	music.playSoud();
	cout << endl << "Button play callback!" << endl;
}

void but_pause_cb(Fl_Widget* w, void* v)
{
	music.pauseSound();
	cout << endl << "Button pause callback!" << endl;
}

void but_loop_cb(Fl_Widget* w, void* v)
{
	music.loopSound();
	cout << endl << "Button loop callback!" << endl;
}

void but_stop_cb(Fl_Widget* w, void* v)
{
	music.stopSound();
	cout << endl << "Button stop callback!" << endl;
}

void but_rewind_cb(Fl_Widget* w, void* v)
{
	music.rewindSound();
	cout << endl << "Button rewind callback!" << endl;
}

void but_forward_cb(Fl_Widget* w, void* v)
{
	music.forwardSound();
	cout << endl << "Button forward callback!" << endl;
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

void but_yes_cb(Fl_Widget* w, void* v)
{
	std::cout << std::endl << "Button YES callback!" << std::endl;
	exit(0);
}

void but_no_cb(Fl_Widget *w, void* v)
{

	std::cout << std::endl << "Button NO callback!" << std::endl;
}


void but_exit_cb(Fl_Widget* w, void* v)
{
	Fl_Window exit_window(200, 90,"Exit");

	
	Fl_Box text(40,10,130,30,"Are you sure to exit?");

	exit_window.color(9);
	exit_window.begin();


	MyButton but_yes(50, 40, 40, 30, "Yes");
	but_yes.shortcut('y');
	but_yes.callback(but_yes_cb);

	MyButton but_no(110, 40, 40, 30, "No");
	but_no.shortcut('n');
	but_no.callback(but_no_cb); // to correct! to fix!
	if (Fl::event_button() == 'n')
	{
		exit(1);
	}


	exit_window.end();
	exit_window.show();
	

		Fl::run();
		~Fl::run();
	
	
	//exit(0);
}


int main()
{
	system("Color 0B");
	std::cout << "Efekt gitarowy - projekt" << std::endl;
	std::cout << "Test Git\n";


	Fl_Window win(400, 200);
	//win.color2(50);
	win.color(150);
	win.begin();

	MyButton but_loadSound(10, 10, 105, 30, "@filenew Load Sound");
	but_loadSound.shortcut('l');
	but_loadSound.callback(but_loadSound_cb);

	MyButton but_volumePlus(170, 10, 30, 30, "+");
	but_volumePlus.shortcut('+');
	but_volumePlus.callback(but_volumePlus_cb);


	MyButton but_volumeMinus(130, 10, 30, 30, "-");
	but_volumeMinus.shortcut('-');
	but_volumeMinus.callback(but_volumeMinus_cb);
	but_volumeMinus.color2(150);
	but_volumeMinus.color(50);

	MyButton but_speedMinus(210, 10, 30, 30, "@<<");
	but_speedMinus.shortcut('z');
	but_speedMinus.callback(but_speedMinus_cb);

	MyButton but_speedPlus(255, 10, 30, 30, "@>>");
	but_speedPlus.shortcut('x');
	but_speedPlus.callback(but_speedPlus_cb);

	MyButton but_exit(300, 10, 50, 30, "Exit");
	but_exit.shortcut(FL_Escape);
	but_exit.callback(but_exit_cb);


	//50

	MyButton but_play(50, 50, 30, 30, "@>");
	but_play.shortcut('s');
	but_play.callback(but_play_cb);
	but_play.color(Fl_Color(100));
	if (music.getActiveSound() == false)
	{
		but_play.color(Fl_Color(250));
	}

	MyButton but_pause(10, 50, 30, 30,"||");
	but_pause.shortcut('p');
	but_pause.callback(but_pause_cb);

	
	MyButton but_loop(90, 50, 30, 30, "@refresh");
	but_loop.shortcut('i');
	but_loop.callback(but_loop_cb);

	
	MyButton but_stop(50, 90, 30, 30, "@square");
	but_stop.shortcut('o');
	but_stop.callback(but_stop_cb);


	MyButton but_rewind(10, 90, 30, 30, "@|<");
	but_rewind.shortcut('a');
	but_rewind.callback(but_rewind_cb);

	MyButton but_forward(90, 90, 30, 30, "@>|");
	but_forward.shortcut('d');
	but_forward.callback(but_forward_cb);

	
	win.end();
	win.show();





	
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


	system("Pause"); */
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

