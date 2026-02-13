#!/bin/bash

encrypt_caesar_shift_3() {
    local input_text="$1"
    local output_text=""
    local char

    for (( i=0; i<${#input_text}; i++ )); do
        char="${input_text:$i:1}"
        if [[ "$char" =~ [a-z] ]]; then
            # Lowercase letters
            shifted_char=$(printf \\$(printf '%03o' $(( ( ( $(printf '%d' "'$char") - 97 + 3 ) % 26 ) + 97 )) ))
        elif [[ "$char" =~ [A-Z] ]]; then
            # Uppercase letters
            shifted_char=$(printf \\$(printf '%03o' $(( ( ( $(printf '%d' "'$char") - 65 + 3 ) % 26 ) + 65 )) ))
        else
            # Non-alphabetic characters remain unchanged
            shifted_char="$char"
        fi
        output_text+="$shifted_char"
    done
    echo "$output_text"
}

# Example usage:
read -p "Enter text to encrypt: " user_input
encrypted_message=$(encrypt_caesar_shift_3 "$user_input")
echo "Encrypted message: $encrypted_message"
