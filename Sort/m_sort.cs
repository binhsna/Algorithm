using System.Diagnostics;
using System.Net.Security;

namespace Sort
{
    public static class SortExtensions
    {
        // Phương thức đổi chỗ 2 phần tử
        public static void Swap(ref int x, ref int y)
        {
            // (y, x) = (x, y); -> Cách làm ngắn gọn
            int temp = x;
            x = y;
            y = temp;

        }
        // Phương pháp Đổi chỗ trực tiếp (Interchange sort)
        public static void InterchangeSort(this int[] obj, string type = "asc")
        {
            for (var i = 0; i < obj.Length - 1; i++)
            {
                for (var j = i + 1; j < obj.Length; j++)
                {
                    if (type == "asc")
                    {
                        if (obj[i] > obj[j])
                        {
                            Swap(ref obj[i], ref obj[j]);
                        }
                    }
                    else if (type == "desc")
                    {
                        if (obj[i] < obj[j])
                        {
                            Swap(ref obj[i], ref obj[j]);
                        }
                    }
                }
            }
        }
        // Phương pháp Nổi bọt(Bubble sort)
        public static void BubbleSort(this int[] obj, string type = "asc")
        {
            for (int i = 0; i < obj.Length - 1; i++)
            {
                for (int j = obj.Length - 1; j > i; j--)
                {
                    if (type == "asc")
                    {
                        if (obj[j] < obj[j - 1])
                            Swap(ref obj[j], ref obj[j - 1]);
                    }
                    else if (type == "desc")
                    {
                        if (obj[j] > obj[j - 1])
                            Swap(ref obj[j], ref obj[j - 1]);
                    }
                }
            }
        }
        // Phương pháp Chèn trực tiếp(Insertion sort)
        public static void InsertionSort(this int[] obj, string type = "asc")
        {
            int pos, x;
            for (int i = 1; i < obj.Length; i++)
            {
                //đoạn obj[0] đã sắp
                x = obj[i];
                pos = i;
                while (pos > 0 && (type == "asc" ? (x < obj[pos - 1]) : (x > obj[pos - 1])))
                {
                    obj[pos] = obj[pos - 1];    // dời chỗ
                    pos--;
                }
                obj[pos] = x;
            }
        }
        // Phương pháp Chọn trực tiếp(Selection sort)
        public static void SelectionSort(this int[] obj, string type = "asc")
        {
            int MinOrMax; // chỉ số phần tử nhỏ / lớn nhất trong dãy hiện hành
            for (int i = 0; i < obj.Length - 1; i++)
            {
                MinOrMax = i;
                for (int j = i + 1; j < obj.Length; j++)
                {
                    if ((type == "asc") ? (obj[j] < obj[MinOrMax]) : (obj[j] > obj[MinOrMax]))
                        MinOrMax = j; // ghi nhận vị trí phần tử nhỏ / lớn nhất
                }
                if (MinOrMax != i)
                    Swap(ref obj[MinOrMax], ref obj[i]);
            }
        }

        // Phương pháp sắp xếp trộn (Merge Sort)
        // Hàm trộn hai mảng con vào nhau theo đúng thứ tự
        public static void Merge(int[] obj, int left, int mid, int right, string type = "asc")
        {
            int n1 = mid - left + 1; // Số phần tử của mảng thứ nhất
            int n2 = right - mid; // Số phần tử của mảng thứ hai

            // Tạo hai mảng tạm để lưu hai mảng con
            int[] LeftArr = new int[n1];
            int[] RightArr = new int[n2];

            // Sao chép phần tử 2 mảng con vào mảng tạm
            for (int ii = 0; ii < n1; ii++)
            {
                LeftArr[ii] = obj[left + ii];
            }

            for (int ii = 0; ii < n2; ii++)
            {
                RightArr[ii] = obj[mid + 1 + ii];
            }
            // current là vị trí hiện tại trong mảng A
            int i = 0, j = 0, current = left;

            // Trộn hai mảng vào nhau theo đúng thứ tự
            while (i < n1 && j < n2)
                if ((type == "asc") ? (LeftArr[i] <= RightArr[j]) : (LeftArr[i] >= RightArr[j]))
                    obj[current++] = LeftArr[i++];
                else
                    obj[current++] = RightArr[j++];

            // Nếu mảng thứ nhất còn phần tử thì copy nó vào mảng A
            while (i < n1)
                obj[current++] = LeftArr[i++];

            // Nếu mảng thứ hai còn phần tử thì copy nó vào mảng A
            while (j < n2)
                obj[current++] = RightArr[j++];

            // Xóa hai mảng tạm đi
            LeftArr = null; RightArr = null;
        }

        // Hàm chia đôi mảng và gọi hàm trộn
        public static void _MergeSort(this int[] obj, int left, int right, string type = "asc")
        {
            // Kiểm tra xem còn chia đôi mảng được không
            if (left < right)
            {
                // Tìm phần tử chính giữa
                // left + (right - left) / 2 tương đương với (left + right) / 2
                // việc này giúp tránh bị tràn số với left, right quá lớn
                int mid = left + (right - left) / 2;

                // Sắp xếp mảng thứ nhất
                _MergeSort(obj, left, mid, type);
                // Sắp xếp mảng thứ hai
                _MergeSort(obj, mid + 1, right, type);

                // Trộn hai mảng đã sắp xếp
                Merge(obj, left, mid, right, type);
            }
        }

        // Phương phấp sắp xếp nhanh (Quick Sort)
        public static void QuickSort(this int[] obj, int left, int right, string type = "asc")
        {
            // Kiểm tra xem nếu mảng có 1 phần tử thì không cần sắp xếp
            if (left >= right)
                return;

            int pivot = obj[(left + right) / 2]; // Chọn phần tử chính giữa dãy làm chốt

            // i là vị trí đầu và j là cuối đoạn
            int i = left, j = right;
            while (i < j)
            {
                while ((type == "asc") ? (obj[i] < pivot) : (obj[i] > pivot)) // Nếu phần tử bên trái nhỏ hơn pivot thì ok, bỏ qua
                    i++;
                while ((type == "asc") ? (obj[j] > pivot) : (obj[j] < pivot)) // Nếu phần tử bên phải nhỏ hơn pivot thì ok, bỏ qua
                    j--;

                // Sau khi kết thúc hai vòng while ở trên thì chắc chắn
                // vị trí A[i] phải lớn hơn pivot và A[j] phải nhỏ hơn pivot
                // nếu i < j
                if (i <= j)
                {
                    if (i < j) // nếu i != j (tức không trùng thì mới cần hoán đổi)
                        Swap(ref obj[i], ref obj[j]); // Thực hiện đổi chổ ta được A[i] < pivot và A[j] > pivot
                    i++;
                    j--;
                }
            }

            // Gọi đệ quy sắp xếp dãy bên trái pivot
            QuickSort(obj, left, j, type);
            // Gọi đệ quy sắp xếp dãy bên phải pivot
            QuickSort(obj, i, right, type);
        }

    }
}