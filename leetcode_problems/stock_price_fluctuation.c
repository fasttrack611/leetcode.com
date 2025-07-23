#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time;
    int price;
} Stock;

typedef struct {
    Stock* data;
    int size;
    int capacity;
    int latest_time;
} StockPrice;

StockPrice* stockPriceCreate() {
    StockPrice* obj = (StockPrice*)malloc(sizeof(StockPrice));
    obj->data = (Stock*)malloc(sizeof(Stock) * 100001);
    obj->size = 0;
    obj->capacity = 100001;
    obj->latest_time = 0;
    return obj;
}

void stockPriceUpdate(StockPrice* obj, int timestamp, int price) {
    obj->latest_time = obj->latest_time > timestamp ? obj->latest_time : timestamp;
    for (int i = 0; i < obj->size; i++) {
        if (obj->data[i].time == timestamp) {
            obj->data[i].price = price;
            return;
        }
    }
    obj->data[obj->size].time = timestamp;
    obj->data[obj->size].price = price;
    obj->size++;
}

int stockPriceCurrent(StockPrice* obj) {
    for (int i = 0; i < obj->size; i++) {
        if (obj->data[i].time == obj->latest_time) {
            return obj->data[i].price;
        }
    }
    return -1;
}

int stockPriceMaximum(StockPrice* obj) {
    int max_price = 0;
    for (int i = 0; i < obj->size; i++) {
        if (obj->data[i].price > max_price) {
            max_price = obj->data[i].price;
        }
    }
    return max_price;
}

int stockPriceMinimum(StockPrice* obj) {
    int min_price = 1000000001;
    for (int i = 0; i < obj->size; i++) {
        if (obj->data[i].price < min_price) {
            min_price = obj->data[i].price;
        }
    }
    return min_price;
}

void stockPriceFree(StockPrice* obj) {
    free(obj->data);
    free(obj);
}

int main() {
    StockPrice* obj = stockPriceCreate();
    stockPriceUpdate(obj, 1, 10);
    stockPriceUpdate(obj, 2, 5);
    printf("Current: %d\n", stockPriceCurrent(obj));
    printf("Maximum: %d\n", stockPriceMaximum(obj));
    stockPriceUpdate(obj, 1, 3);
    printf("Maximum: %d\n", stockPriceMaximum(obj));
    stockPriceUpdate(obj, 4, 2);
    printf("Minimum: %d\n", stockPriceMinimum(obj));
    stockPriceFree(obj);
    return 0;
}
