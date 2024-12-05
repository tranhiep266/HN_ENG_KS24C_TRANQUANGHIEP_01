#include <stdio.h>
int main(){
	int menu, length, currentLength, arr[100];
	for(;;){
		printf("\nMENU\n");
		printf("1. Nhap so phan tu va gia tri cho mang\n");
		printf("2. In ra gia tri cac phan tu trong mang theo dang(arr[0]=1,arr[1]=5...)\n");
		printf("3. Dem so luong cac so nguyen to co trong mang\n");
		printf("4. Tim gia tri nho thu hai trong mang\n");
		printf("5. Them mot phan tu vao trong mang\n");
		printf("6. Xoa phan tu tai mot vi tri cu the\n");
		printf("7. Sap xep mang theo thu tu giam dan\n");
		printf("8. Cho nguoi dung nhap vao mot phan tu,tim kiem xem phan tu do co ton tai khong\n");
		printf("9. Xoa toan bo phan tu trung lap trong mang va hien thi toan bo phan tu doc nhat co o trong mang\n");
		printf("10. Dao nguoc thu tu cua cac phan tu co trong mang\n");
		printf("11. Thoat\n");
		printf("Lua chon cua ban: \n");
		scanf("%d",&menu);
		printf("\n");
		if(menu==1){
			for(;;){
				printf("Nhap so phan tu cua mang: ");
			    scanf("%d",&length);
			    if(length>0){
			    	currentLength=length;
			    	break;
				}
			}
			printf("Nhap gia tri cho phan tu: \n");
			for(int i=0;i<length;i++){
				scanf("%d",&arr[i]);
			}
			printf("\n");
		}
		
		else if(menu==2){
			for(int i=0;i<length;i++){
				printf("arr[%d] = %d \n",i,arr[i]);
			}
			printf("\n");
		}
		
		else if(menu==3){
			int temp_snt=0;
			for(int i=0;i<length;i++){
				int temp=1;
				if(arr[i]<2){
					temp=0;
				}else{
					for(int j=2;j*j<=arr[i];j++){
					   if(arr[i]%j==0){
						temp=0;
						break;
					    }
				    }
				}
				if(temp){
					temp_snt++;
				}
			}
			printf("So luong cac so nguyen to trong mang: %d",temp_snt);
            printf("\n");
		}
		
		else if(menu==4){
			printf("Gia tri nho thu hai trong mang: %d",arr[1]);
            printf("\n");
		}
		
		else if(menu==5){
			int posi_add,value_add;
            printf("Nhap gia tri muon them: ");
            scanf("%d",&value_add);
            printf("Nhap vi tri muon them (1 den %d): ",currentLength+1);
            scanf("%d",&posi_add);
            if(posi_add>=1&&posi_add<=currentLength+1){
                for(int i=currentLength;i>=posi_add;i--){
                    arr[i]=arr[i-1];
                }
                arr[posi_add-1]=value_add;
                currentLength++;
                printf("Mang sau khi them: ");
                for(int i=0;i<currentLength;i++){
                    printf("%d ",arr[i]);
                }
                printf("\n");
            }else{
                printf("Vi tri khong hop le \n");
            }
            printf("\n");
		}
		
		else if(menu==6){
			int posi_del;
			printf("Nhap vi tri can xoa (1 den %d): ",currentLength);
            scanf("%d",&posi_del);
            if(posi_del>=1&&posi_del<=currentLength){
                for(int i=posi_del-1;i<currentLength-1;i++){
                    arr[i]=arr[i+1];
                }
            currentLength--;
            printf("Mang sau khi xoa: ");
                for(int i=0;i<currentLength;i++){
                    printf("%d ",arr[i]);
                }
            printf("\n");
            }else{
                printf("Vi tri khong hop le \n");
            }
		}
		
		else if(menu==7){
			for(int i=1;i<currentLength;i++){
                int key=arr[i];
                int j=i-1;
                while(j>=0&&arr[j]<key){
                    arr[j+1]=arr[j];
                    j=j-1;
                }
                arr[j+1]=key;
            }
            printf("Mang sau khi sap xep: ");
            for(int i=0;i<currentLength;i++){
                printf("%d ",arr[i]);
            }
            printf("\n");
		}
		
		else if(menu==8){
			for(int i=1;i<currentLength;i++){
                int key=arr[i];
                int j=i-1;
                while(j>=0&&arr[j]>key){
                    arr[j+1]=arr[j];
                    j=j-1;
                }
                arr[j+1]=key;
            }
            int value_find;
            printf("Nhap so nguyen can tim: ");
            scanf("%d",&value_find);
            int left=0,right=currentLength-1,result=-1;
            while(left<=right){
                int k=left+(right-left)/2;
                if(arr[k]==value_find){
                    result=k;
                    break;
                }
                if(arr[k]<value_find){
                    left=k+1;
                }else{
                    right=k-1;
                }
            }
            if(result!=-1){
                printf("Phan tu %d duoc tim thay \n", value_find);
            }else{
               printf("Phan tu %d khong duoc tim thay trong mang\n", value_find);
            }
			printf("\n");		
		}
		
		else if(menu==9){
		}
		
		else if(menu==10){
		}
		
		else if(menu==11){
			printf("Thoat");
			break;
		}
	}
	return 0;
}
