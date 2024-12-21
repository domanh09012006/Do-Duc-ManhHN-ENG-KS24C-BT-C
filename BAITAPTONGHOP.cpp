#include<stdio.h>
#include<string.h>

int main(){
	struct Menu{
	int STT;
	char member[50];
	int price;
	};
	struct Menu DishMenu[100]={
		{1,"Ga ran",30},
		{2,"Lau",100},
		{3,"Com tam",25},
		{4,"Pho",30},
		{5,"Vit quay",100}
	};
	int n = 5, a=0, choice, found=0;
	int pos;
	char newmember[50];
	int newprice;
	while(a<1){
		printf("\n---MENU---\n");
		printf("1.In ra mon an\n");
		printf("2.Them mon an vao cuoi menu\n");
		printf("3.Sua mon an\n");
		printf("4.Xoa mon an o cuoi menu\n");
		printf("5.Sap xep mon an theo gia\n");
		printf("6.Tim mon an\n");
		printf("7.Thoat\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &choice);
		getchar();
		switch(choice){
			case 1://In ra mon an
				printf("Mon an trong DishMenu la: ");
				for(int i=0; i<n; i++){
					printf("\n%d. %s: %d",DishMenu[i].STT, DishMenu[i].member, DishMenu[i].price);
				}
			break;
			case 2://Them mon an vao cuoi menu
				printf("Nhap ten mon an can them: ");
				fgets(newmember,sizeof(newmember),stdin);
				newmember[strcspn(newmember, "\n")]='\0';
				printf("Nhap gia mon an: ");
				scanf("%d", &newprice);
				fflush(stdin);
				DishMenu[n].STT = n+1;
				strcpy(DishMenu[n].member,newmember);
				DishMenu[n].price=newprice;
				n++;
				printf("Mon an trong DishMenu la: ");
				for(int i=0; i<n; i++){
					printf("\n%d. %s: %d",DishMenu[i].STT, DishMenu[i].member, DishMenu[i].price);
				}
			break;
			case 3://Sua mon an
				printf("Nhap vi tri can sua mon an: ");
				scanf("%d", &pos);
				fflush(stdin);
				if(pos<0 || pos>n){
					printf("Khong co mon an nay");
				}else{
					printf("Sua ten mon an: ");
					fgets(newmember,sizeof(newmember),stdin);
					newmember[strcspn(newmember,"\n")]='\0';
					printf("Sua gia mon an: ");
					scanf("%d", &newprice);
					fflush(stdin);
					strcpy(DishMenu[pos].member,newmember);
					DishMenu[pos].price=newprice;
					for(int i=0; i<n; i++){
					printf("\n%d. %s: %d",DishMenu[i].STT, DishMenu[i].member, DishMenu[i].price);
					}
				}
			break;
			case 4://Xoa mon an cuoi menu
				if(n>0){
					n--;
					printf("Da xoa mon an: %d.%s:%d\n", DishMenu[n].STT, DishMenu[n].member, DishMenu[n].price);
				}
				printf("Menu sao khi chinh sua la: ");
				for(int i=0; i<n; i++){
					printf("\n%d.%s:%d",DishMenu[i].STT, DishMenu[i].member, DishMenu[i].price);
				}
			break;
			case 5://Sap xep tang dan mon an theo gia
				for (int i=0; i<n-1; i++) {
		                    for (int j=i+1; j<n; j++) {
		                        if (DishMenu[i].price>DishMenu[j].price) {
		                            struct Menu temp = DishMenu[i];
		                            DishMenu[i] = DishMenu[j];
		                            DishMenu[j] = temp;
		                        }
		                    }
		                }
			        printf("Mon an sau khi sap xep la: ");
			        for(int i=0; i<n; i++){
					printf("\n%d. %s: %d",DishMenu[i].STT, DishMenu[i].member, DishMenu[i].price);
				}
			break;
			case 6://Tim mon an
				printf("Nhap ten mon an can tim: ");
		                fgets(newmember, sizeof(newmember), stdin);
		                newmember[strcspn(newmember, "\n")] = '\0';
		                printf("Ket qua tim kiem:\n");
		                for (int i=0; i<n; i++) {
		                    if (strstr(DishMenu[i].member, newmember)) {
		                        printf("Mon an co trong DishMenu");
		                        found=1;
		                    }
		                }
		                if (!found) {
		                    printf("Khong tim thay mon an!\n");
		                }
			break;
			case 7://Thoat
				printf("Thoat!");
				a++;
				return 0;
			break;
			default:
				printf("Khong co lua chon nay!");
		}
	}
}

