def xor(a, b):
    result = []
    for i in range(1, len(b)):
        if a[i] == b[i]:
            result.append('0')
        else:
            result.append('1')
    return ''.join(result)


def mod2div(divident, divisor):
    pick = len(divisor)
    tmp = divident[0: pick]
    while pick < len(divident):
        if tmp[0] == '1':
            tmp = xor(divisor, tmp) + divident[pick]
        else:
            tmp = xor('0' * pick, tmp) + divident[pick]
        pick += 1
    if tmp[0] == '1':
        tmp = xor(divisor, tmp)
    else:
        tmp = xor('0' * pick, tmp)
    checkword = tmp
    return checkword


def crcCheck(data, poly, mode):
    l_key = len(poly)
    appended_data = data + '0' * (l_key - 1)
    remainder = mod2div(appended_data, poly)
    if mode:
        codeword = data + remainder
        print("Remainder : ", remainder)
        print("Encoded Data (Data + Remainder) : ", codeword)
        return codeword
    else:
        return remainder


# CRC-8 100000111
# CRC-10 11000110101
# CRC-16 10001000000100001
def main():
    data = input("Enter the input in binary format: ")
    poly = "100000111"
    print("CRC-8 Used here ")
    sentData = crcCheck(data, poly, 1)
    crcAtReceiver = crcCheck(sentData, poly, 0)
    print("The remainder on CRC check at receiver side: ", crcAtReceiver)
    if crcAtReceiver == "0" * (len(sentData)-len(data)):
        print("There is no error at receiver side")
    else:
        print("There is error at receiver side")


if __name__ == '__main__':
    main()
