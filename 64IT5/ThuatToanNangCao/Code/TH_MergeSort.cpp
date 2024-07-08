#include <iostream>
using namespace std;

// Gop 2 mang con a[head...mid] và a[mid+1...tail]
void merge(int a[], int head, int mid, int tail) // Ham trôn xêp
{
    int i, j, k;
    int n1 = mid - head + 1;
    int n2 =  tail - mid;
 
    /* Tao các mang con luu duoc chia doi tu mang truoc do */
    int a1[n1], a2[n2];
 
    /* Chuyên du lieu vao 2 mang duoc chia doi ra*/
    for (i = 0; i < n1; i++)
        a1[i] = a[head + i];
    for (j = 0; j < n2; j++)
        a2[j] = a[mid + 1+ j];
 
    /* Lân luot so sanh tung cap phân tu trong 2 mang con, 
	dua phan tu nho hon vao bang luu*/
    i = 0; // Khoi tao chi so bat dau cua mang con a1
    j = 0; // Khoi tao chi so bat dau cua mang con a2
    k = head; // Chi so bat dau cua mang luu kêt qua, su dung luon ten mang a ban dau
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
 
    /* Copy các phân tu còn lai cua mang a1 vào a nêu có */
    while (i < n1)
    {
        a[k] = a1[i];
        i++;
        k++;
    }
 
    /* Copy các phân tu còn lai cua mang a2 vào a nêu có */
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
        // Tuong tu (head+tail)/2, nhung cách này tránh tràn sô khi head và tail lon
        int mid = head+(tail-head)/2;
 
        // Goi ham dê quy tiêp tuc chia dôi tung nua mang
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
