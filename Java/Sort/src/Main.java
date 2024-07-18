/*
 * Sorting in Java
 * Interchange Sort, Bubble Sort, Selection Sort: Phù hợp với mảng có kích thước nhỏ
 * Quick Sort, Merge Sort, Heapsort: Hiệu quả với các mảng lớn (Nhưng yêu cầu thêm bộ nhớ)
 * */

public class Main {
    // Hoán đổi giá trị của 2 phần tử
    public static void Swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Phương pháp đổi chỗ trực tiếp
    //=> O(n^2)
    public static void InterchangeSort(int[] arr, String type) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (type.equals("desc")) {
                    if (arr[i] < arr[j]) Swap(arr, i, j);
                } else {
                    if (arr[i] > arr[j]) Swap(arr, i, j);
                }
            }
        }
    }

    // Phương pháp sắp xếp nổi bọt
    //=> O(n^2)
    public static void BubbleSort(int[] arr, String type) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = n - 1; j > i; j--) {
                if (type.equals("desc")) {
                    if (arr[j] > arr[j - 1]) Swap(arr, j, j - 1);
                } else {
                    if (arr[j] < arr[j - 1]) Swap(arr, j, j - 1);
                }
            }
        }
    }

    // Phương pháp chèn trực tiếp
    // O(n^2)
    public static void InsertionSort(int[] arr, String type) {
        int n = arr.length;
        int pos, x;
        // Duyệt từ phần tử thứ 2
        for (int i = 1; i < n; i++) {
            x = arr[i];
            pos = i;
            while (pos > 0 && (type.equals("desc") ? (x > arr[pos - 1]) : (x < arr[pos - 1]))) {
                arr[pos] = arr[pos - 1];    // dời chỗ
                pos--;
            }
            arr[pos] = x;
        }
    }

    // Phương pháp chọn trực tiếp
    // O(n^2)
    public static void SelectionSort(int[] arr, String type) {
        int index;// chỉ số phần min/max trong dãy hiện hành
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            index = i;
            for (int j = i + 1; j < n; j++) {
                if (type.equals("desc")) {
                    if (arr[j] > arr[index]) {
                        index = j; // ghi nhận vị trí phần tử max
                    }
                } else {
                    if (arr[j] < arr[index]) {
                        index = j; // ghi nhận vị trí phần tử min
                    }
                }
            }
            if (index != i) {
                Swap(arr, index, i);
            }
        }
    }

    // Thuật toán QuickSort
    // O(nlogn)
    public static void QuickSort(int[] arr, int start, int end, String type) {
        if (start < end) {
            int pivot = partition(arr, start, end, type);

            QuickSort(arr, start, pivot - 1, type);

            QuickSort(arr, pivot + 1, end, type);
        }
    }

    // Phân vùng sử dụng lược đồ phân vùng Lomuto
    private static int partition(int[] arr, int start, int end, String type) {
        int pivot = arr[end]; // Chọn mốc là phần tử cuối
        int pIndex = start;
        for (int i = start; i < end; i++) {
            if (type.equals("desc")) {
                if (arr[i] >= pivot) {
                    Swap(arr, i, pIndex);
                    pIndex++;
                }
            } else {
                if (arr[i] <= pivot) {
                    Swap(arr, i, pIndex);
                    pIndex++;
                }
            }
        }
        Swap(arr, end, pIndex);
        return pIndex;
    }

    // Thuật toán MergeSort
    // O(nlogn)
    public static void Merge(int[] obj, int left, int mid, int right, String type) {
        int n1 = mid - left + 1; // Số phần tử của mảng thứ nhất
        int n2 = right - mid; // Số phần tử của mảng thứ hai

        // Tạo hai mảng tạm để lưu hai mảng con
        int[] LeftArr = new int[n1];
        int[] RightArr = new int[n2];

        // Sao chép phần tử 2 mảng con vào mảng tạm
        for (int i = 0; i < n1; i++) {
            LeftArr[i] = obj[left + i];
        }

        for (int j = 0; j < n2; j++) {
            RightArr[j] = obj[mid + 1 + j];
        }
        // current là vị trí hiện tại trong mảng A
        int i = 0, j = 0, current = left;

        // Trộn hai mảng vào nhau theo đúng thứ tự
        while (i < n1 && j < n2)
            if ((type.equals("asc")) ? (LeftArr[i] <= RightArr[j]) : (LeftArr[i] >= RightArr[j]))
                obj[current++] = LeftArr[i++];
            else
                obj[current++] = RightArr[j++];

        // Nếu mảng thứ nhất còn phần tử thì copy nó vào mảng A
        while (i < n1)
            obj[current++] = LeftArr[i++];

        // Nếu mảng thứ hai còn phần tử thì copy nó vào mảng A
        while (j < n2)
            obj[current++] = RightArr[j++];
    }

    // Hàm chia đôi mảng và gọi hàm trộn
    public static void MergeSort(int[] obj, int left, int right, String type) {
        // Kiểm tra xem còn chia đôi mảng được không
        if (left < right) {
            // Tìm phần tử chính giữa
            // left + (right - left) / 2 tương đương với (left + right) / 2
            // việc này giúp tránh bị tràn số với left, right quá lớn
            int mid = left + (right - left) / 2;

            // Sắp xếp mảng thứ nhất
            MergeSort(obj, left, mid, type);
            // Sắp xếp mảng thứ hai
            MergeSort(obj, mid + 1, right, type);

            // Trộn hai mảng đã sắp xếp
            Merge(obj, left, mid, right, type);
        }
    }

    // In các phần tử của mảng
    static void printArray(int[] arr) {
        for (int a : arr) System.out.print(a + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        int[] arr = {12, 11, 100, 1000, 99, 89, 20, 555};
        System.out.println("Mảng ban đầu:");
        printArray(arr);
        MergeSort(arr, 0, arr.length - 1, "asc");
        System.out.println("Mảng sau khi sắp xếp:");
        printArray(arr);
    }
}