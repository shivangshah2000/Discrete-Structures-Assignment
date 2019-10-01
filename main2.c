/**
 * The question gives a mapping of courses where some courses are pre-requisites for other courses
 * The task is to find an order of courses where all the pre-requisites are cleared before the course
 *
 * The problem can be modelled as a single directional graph
 *
 * The approach is to store the graph as a square matrix with edges from pre-requisite to course
 * Courses having no pre-requisites are done first
 */
#include <stdio.h>
typedef long long ll;
typedef unsigned long long ull;

int find(int n, int arr[n], int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}
int main() {
    int num_courses, courses[10] = {0};
    scanf("%d", &num_courses);
    for (int i = 0; i < num_courses; i++) {
        scanf("%d", &courses[i]);
    }
    int connections[10][10], queries, prereq, course;
    for (int i = 0; i < num_courses; i++) {
        for (int j = 0; j < num_courses; j++) {
            connections[i][j] = 0;
        }
    }
    scanf("%d", &queries);
    for (int i = 0; i < queries; i++) {
        scanf("%d %d", &prereq, &course);
        prereq = find(num_courses, courses, prereq);
        course = find(num_courses, courses, course);
        connections[prereq][course] = 1;
    }
    int answer[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int pre;
    for (int i = 0; i < num_courses;) {
        for (int j = 0; j < num_courses; j++) {
            pre = 0;
            for (int k = 0; k < num_courses; k++) {
                if (connections[k][j]) {
                    pre++;
                    break;
                }
            }
            if (!pre) {
                answer[i++] = j;
                for (int k = 0; k < num_courses; k++) {
                    if (connections[j][k] != -1){ connections[j][k] = 0;
                    connections[k][j] = -1;}
                }
            }
        }
    }
    for (int i = 0; i < num_courses; i++) {
        printf("%d ", courses[answer[i]]);
    }
    printf("\n");
    return 0;
}
