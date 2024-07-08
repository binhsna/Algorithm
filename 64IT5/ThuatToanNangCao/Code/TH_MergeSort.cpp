#include <iostream>
using namespace std;

// Gop 2 mang con a[head...mid] v� a[mid+1...tail]
void merge(int a[], int head, int mid, int tail) // Ham tr�n x�p
{
    int i, j, k;
    int n1 = mid - head + 1;
    int n2 =  tail - mid;
 
    /* Tao c�c mang con luu duoc chia doi tu mang truoc do */
    int a1[n1], a2[n2];
 
    /* Chuy�n du lieu vao 2 mang duoc chia doi ra*/
    for (i = 0; i < n1; i++)
        a1[i] = a[head + i];
    for (j = 0; j < n2; j++)
        a2[j] = a[mid + 1+ j];
 
    /* L�n luot so sanh tung cap ph�n tu trong 2 mang con, 
	dua phan tu nho hon vao bang luu*/
    i = 0; // Khoi tao chi so bat dau cua mang con a1
    j = 0; // Khoi tao chi so bat dau cua mang con a2
    k = head; // Chi so bat dau cua mang luu k�t qua, su dung luon ten mang a ban dau
    while (i < n1 && j < n2)
    {
        if (a1[i] <= a2[j])
        {
            a[k] = a1[i];
            i++;
        }
        else
        {
            a[k] = a2[j];
            j++;
        }
        k++;
    }
 
    /* Copy c�c ph�n tu c�n lai cua mang a1 v�o a n�u c� */
    while (i < n1)
    {
        a[k] = a1[i];
        i++;
        k++;
    }
 
    /* Copy c�c ph�n tu c�n lai cua mang a2 v�o a n�u c� */
    while (j < n2)
    {
        a[k] = a2[j];
        j++;
        k++;
    }
}
// Ham sap xep tron MergeSort
void MS(int a[], int head, int tail)
{
    if (head < tail)
    {
        // Tuong tu (head+tail)/2, nhung c�ch n�y tr�nh tr�n s� khi head v� tail lon
        int mid = head+(tail-head)/2;
 
        // Goi ham d� quy ti�p tuc chia d�i tung nua mang
        MS(a, head, mid);
        MS(a, mid+1, tail);
 		// Tron lai tung mang con
        merge(a, head, mid, tail);
    }
}
// Ham hien thi mang
void XuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout<<endl;
}

int main()
{
    int a[] = {12, 11, 13, 5, 6, 7,4};
    int n = sizeof(a)/sizeof(a[0]);
 	MS(a, 0, n - 1);
    cout << "Mang sau khi duoc sap xep: \n";
    XuatMang(a,n);
    return 0;
}
