int getHourglass(int** arr) {
    int high = -100;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int actual = 0;
            actual += arr[i][j] + arr[i][j+1] + arr[i][j+2];
            actual += arr[i+1][j+1];
            actual += arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            if (actual > high)
                high = actual;
        }
    }
    return high;
}
