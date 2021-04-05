#pragma once
class FileCommand
{
	enum Command {
		Open,
		Close,
		Save,
		SaveAs,
		Help,
		Exit
	};

	void executeCommand(Command command);
	void open(Command open);
	void close(Command open);
	void save(Command open);
	void saveAs(Command open);
	void help(Command open);
	void exit(Command open);



};

