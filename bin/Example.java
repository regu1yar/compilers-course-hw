class Example {
    public static void main() {
        int[] intArr;
        intArr = new int[10];
        intArr[2] = -(42 - 22);
        System.out.println(intArr[2]);

        boolean flag;
        flag = true && (intArr[2] == -20);
        if (flag) {
            intArr[3] = 0;
            System.out.println(intArr[2] + 20);
        } else {
            intArr[3] = 1;
            System.out.println(intArr[2] - 20);
        }
        System.out.println(intArr[1 + 1 + 1]);
    }
}
