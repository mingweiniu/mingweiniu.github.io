//reference from linux系統程式設計
/*
 * [Arch@Linux]$ sudo pacman -Syu libmariadbclient
 * [Arch@Linux]$ gcc -o query -I/usr/include/mysql -L/usr/lib/mysql - lmysqlclient
 */
#include <stdio.h>
#include <mysql/mysql.h>
int main() {
	MYSQL mysql;
	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "root", "rootpw", "student", 0, NULL, 0)) {
		printf("Error connecting to database: %s\n", mysql_error(&mysql));
		return 0;
	}
	else printf("Connected MySQL successfully!\n");

	mysql_close(&mysql);
	return 0;
}
