float *mergeSort(float *up, float *down, unsigned int left, unsigned int right) {
    if(left == right) {
        down[left] = up[left];
        return down;
    }

    unsigned int middle = (left + right)/2;

    // Разделяем данные пополам
    float *l_buff = mergeSort(up, down, left, middle);
    float *r_buff = mergeSort(up, down, middle + 1, right);

    // Сливаем 2 отсортированных половинки
    float *target = l_buff == up ? down : up;

    unsigned int l_cur = left,
                 r_cur = middle + 1;

    for(unsigned int i = left; i <= right; i++) {
        if(l_cur <= middle && r_cur <= right) {
            if(l_buff[l_cur] < r_buff[r_cur]) {
                target[i] = l_buff[l_cur];
                l_cur++;
            }
            else {
                target[i] = r_buff[r_cur];
                r_cur++;
            }
        }
        else if(l_cur <= middle) {
            target[i] = l_buff[l_cur];
            l_cur++;
        }
        else {
            target[i] = r_buff[r_cur];
            r_cur++;
        }
    }
    return target;
}
