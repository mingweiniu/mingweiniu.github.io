//reference from linux系統程式設計
/*
 * [Arch@Linux]$ sudo pacman -Syu libmariadbclient
 * [Arch@Linux]$ gcc -o query -I/usr/include/mysql -L/usr/lib/mysql - lmysqlclient
 */
#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>
int main() {
	MYSQL mysql;
	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "root", "rootpw", "student", 0, NULL, 0)) {
		printf("Error connecting to database: %s\n", mysql_error(&mysql));
		return 0;
	}
	else printf("Connected MySQL successfully!\n");
	//Inquire SQL syntax
	const char *query;
	query = "select *from student;";
	if (mysql_real_query(&mysql, query, (unsigned long)strlen(query))) {
		//fail if not zero
		printf("query failed!\n");
		return 0;
	}
	else { //query successful
		printf("[%s] made..\n", query);
		MYSQL_RES *res;
		res = mysql_store_result(&mysql);
		MYSQL_ROW row;
		while (row = mysql_fetch_row(res)) {
			for (int t = 0; t < mysql_num_fields(res); t++)
				printf("%s", row[t]);
			printf("\n");
		}
	}
	mysql_close(&mysql);
	return 0;
}
