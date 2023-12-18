
#include "Vector.h"
#include "Queue.h"
#include "Program.h"
#include "HangHoa.h"
#include "DonHang.h"
#include "Account.h"

int main()
{
	system("title Ban Hang Online");
	Program program;
	program.getAdmin();
	program.getItems();
	program.run();
	return 0;
}
