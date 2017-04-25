#include "List.h"

struct Node {
    ElementType Element;
    Position Next;
};

int IsEmpty(List L) {
    return L->Next == Null;
}

int IsLast(Position P, List L) {
    return P->Next == Null;
}

Position Find(ElementType X, List L) {
    Position P;
    P = L->Next;
    while (P != NULL && P->Element != X)
        P = P->Next;
    return P;
}

Position FindPosition(ElementType X, List L) {
    Position P;
    P = L;
    while (P->Next != NULL && P->Next->Element != X)
        P = P->Next;
    return P;
}

void Delete(ElementType X, List L) {
    Position P, TmpCell;
    P = FindPrevious(X, L);
    if (!IsLast(P, L)) {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}