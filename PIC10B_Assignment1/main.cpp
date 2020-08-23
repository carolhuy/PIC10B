#include"StudentClub.h"

int main()
{
	StudentClub math("MATHBRUINS");
	Student* jess = new Student("Jess", 20);
	Student* john = new Student("John", 50);
	Student* kate = new Student("Kate", 20);
	Student* mary = new Student("Mary", 30);
	// set president/treasurer
	math.set_president(john);
	math.set_treasurer(john);
	// update members
	math.add_member(kate);
	math.add_member(mary);
	math.add_member(jess);
	math.add_member(john);
	//print Student club info
	math.print();
	// find youngest students and print their names
	std::vector<std::string> youth;
	youth = find_youngest(math.get_member());
	std::cout << std::setw(20) << "Youngest members:";
	for (int i = 0; i < youth.size(); ++i)
		std::cout << " " << youth[i];
	std::cout << std::endl;

	return 0;
}
