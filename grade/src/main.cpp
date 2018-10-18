#include <iostream>
#include <string>

#include "liblog.hpp"

static float calcGrade(float engagement, float mastery, float progression)
{
	return (engagement * 2 + mastery * 5 + progression * 3) / 10 * 100;
}

int main(int argc, const char* argv[])
{
	Logger console = Logger(loglevel_t::everything, "console.log");

	console << "GradeCalc v0.1" << newl;
	console << "by Brendan Gowen" << newl;
	console << "https://github.com/akachronix" << newl;
	console << newl;

	float engagement_score;
	console << "Enter scored points (Student Engagement with Standards) ";
	console >> engagement_score;

	float engagement_total;
	console << "Enter total points (Student Engagement with Standards) ";
	console >> engagement_total;

	console << newl;

	float mastery_score;
	console << "Enter scored points (Student Mastery of Standards) ";
	console >> mastery_score;

	float mastery_total;
	console << "Enter total points (Student Mastery of Standards) ";
	console >> mastery_total;

	console << newl;

	float progression_score;
	console << "Enter scored points (Student Progression with Standards) ";
	console >> progression_score;

	float progression_total;
	console << "Enter total points (Student Progression with Standards) ";
	console >> progression_total;

	console << newl;

	float grade = calcGrade(
		engagement_score / engagement_total,
		mastery_score / mastery_total,
		progression_score / progression_total
	);

	console << "Your grade is " << grade << "%." << newl;

	return 0;
}
