#!/usr/bin/python3

def input_data_size() -> int:
    data_size = int(input())
    if data_size <= 0:
        raise ValueError("data_size <= 0")
    return data_size


def input_dim() -> int:
    dim = int(input())
    if dim <= 0:
        raise ValueError("dim <= 0")
    return dim


def input_dists_size() -> int:
    dists_size = int(input())
    if dists_size <= 0:
        raise ValueError("dists_size <= 0")
    return dists_size


def input_weights(dists_size:int) -> list[float]:
    weights_l = input().split(',')
    if not len(weights_l) == dists_size:
        raise ValueError("weights length != dists_size")
    weights = [float(s) for s in weights_l]
    sum = 0.0
    for w in weights:
        if w < 0.0:
            raise ValueError("weight < 0")
        sum += w
    if sum <= 0.0:
        return [1.0 / float(dists_size)] * dists_size
    else:
        for i in range(dists_size):
            weights[i] /= sum
        return weights


def input_avr(dim:int) -> list[float]:
    avr_l = input().split(',')
    if not len(avr_l) == dim:
        raise ValueError("avr length != dists_size")
    avr = [float(s) for s in avr_l]
    return avr


def input_var(dim:int) -> list[list[float]]:
    var = []
    for j in range(dim):
        var_r_l = input().split(',')
        if not len(var_r_l) == dim:
            raise ValueError("col of var != dim")
        var.append([float(s) for s in var_r_l])
    return var


if __name__ == "__main__":
    data_size = input_data_size()

    dim = input_dim()

    dists_size = input_dists_size()

    weights = input_weights(dists_size)

    avrs = []
    for i in range(dists_size):
        avrs.append(input_avr(dim))

    vars = []
    for i in range(dists_size):
        vars.append(input_var(dim))

    print(data_size)
    print(dim)
    print(dists_size)
    for i in range(dists_size):
        print(weights[i])
    for i in range(dists_size):
        for j in range(dim):
            print(avrs[i][j])
    for i in range(dists_size):
        for j in range(dim):
            for k in range(dim):
                print(vars[i][j][k])
    