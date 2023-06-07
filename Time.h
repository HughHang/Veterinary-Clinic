#ifndef TIME_H
#define TIME_H

class Time
{
	friend ostream& operator<<(ostream&, Time&);

	public:
		Time(int=0, int=0);
		void setTime(int, int);
		/*
		Purpose: To add amount of time to time
		In: h, m 
		*/
		void add(int, int);

		bool operator==(Time&);
		bool operator!=(Time&);
		bool operator<(Time&);
		bool operator<=(Time&);
		bool operator>(Time&);
		bool operator>=(Time&);


	private:
		int hours;
		int minutes;
		int convertToMins() const;

};

#endif
