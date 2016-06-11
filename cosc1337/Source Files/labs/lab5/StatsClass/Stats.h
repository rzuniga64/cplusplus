#pragma once
#ifndef STATS_H
#define STATS_H

const int ARRAY_SIZE = 30;

class Stats
{
public:
	Stats();
	bool storeValue(double value);
	void display();
	double getCapacity();
	double total();
	double average();
	double lowest();
	double highest();

private:
	double statsArr[ARRAY_SIZE];
	int capacity;
};

#endif