public class Main {
    //=> Font color
    public static final String ANSI_RESET = "\u001B[0m";
    public static final String ANSI_BLACK = "\u001B[30m";
    public static final String ANSI_RED = "\u001B[31m";
    public static final String ANSI_GREEN = "\u001B[32m";
    public static final String ANSI_YELLOW = "\u001B[33m";
    public static final String ANSI_BLUE = "\u001B[34m";
    public static final String ANSI_PURPLE = "\u001B[35m";
    public static final String ANSI_CYAN = "\u001B[36m";
    public static final String ANSI_WHITE = "\u001B[37m";

    public static void PrintWithColor(String color, String content) {
        System.out.println(color + content + ANSI_RESET);
    }

    // Tìm kiếm tuyến tính
    // O(n)
    public static int LinearSearch(int[] arr, int target) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }

    // Tìm kiếm nhị phân (Dùng trong một mảng đã được sắp xếp)
    // O(logn)
    public static int BinarySearchRecursive(int[] a, int l, int r, int target) {
        int mid = (l + r) / 2;
        if (r - l < 0) {
            return -1;
        }
        if (target == a[mid]) {
            return mid;
        } else if (target >= a[mid]) {
            return BinarySearchRecursive(a, mid + 1, r, target);
        } else {
            return BinarySearchRecursive(a, l, mid - 1, target);
        }
    }

    // Tìm kiếm tam phân
    // O(logn)
    public static int TernarySearch(int[] a, int target, int n) {
        int l = 0;
        int r = n - 1;
        while (r - l >= 0) {
            int partiton = (r - l) / 3;
            int mid1 = l + partiton;
            int mid2 = r - partiton;

            if (target == a[mid1])
                return mid1;
            else if (target == a[mid2])
                return mid2;
            else if (target < a[mid1])
                r = mid1 - 1;
            else if (target > a[mid2])
                l = mid2 + 1;
            else {
                l = mid1 + 1;
                r = mid2 - 1;
            }
        }
        return -1;
    }

    // Tìm kiếm nhảy
    // O(log(sqrt(n)))
    public static int JumpSearchIterative(int[] a, int target) {
        int blockSize = (int) Math.sqrt(a.length);
        int start = 0;
        int next = blockSize;

        while (start < a.length && target > a[next - 1]) {
            start = next;
            next = next + blockSize;

            if (next >= a.length)
                next = a.length;
        }

        for (int i = start; i < next; i++) {
            if (target == a[i])
                return i;
        }

        return -1;
    }

    // Tìm kiếm theo cấp số nhân (Cải tiến so với tìm kiếm nhị phân)
    // O(log(i)) -> i là chỉ số của phần tử cần tìm kiếm
    public static int ExpoSearch(int[] a, int target) {
        int bound = 1;
        while (bound < a.length && target > a[bound])
            bound *= 2;

        int left_bound = bound / 2;
        int right_bound = Math.min(bound, a.length - 1);
        int answer = BinarySearchRecursive(a, left_bound, right_bound, target);
        return answer;
    }

    public static void main(String[] args) {
        int[] arr = {11, 12, 42, 60, 89, 100};
        int target = 12;
        // int res = BinarySearchRecursive(arr, 0, arr.length - 1, target);
        int res = ExpoSearch(arr, target);
        if (res != -1) {
            PrintWithColor(ANSI_GREEN, "Target: " + target + " is in array");
        } else {
            PrintWithColor(ANSI_RED, "Target: " + target + " is not in array");
        }
    }
}