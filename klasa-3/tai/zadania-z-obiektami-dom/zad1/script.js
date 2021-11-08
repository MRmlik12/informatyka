const characters = "abcdefghijklmnopqrstuvwsyzABCDEFGHIJKLMNOPQRSTUVWSYZ1234567890!@#$%&*"
let passwordLengthInput = document.getElementById("passwordLength")
let generateButton = document.getElementById("generate")

const generatePassword = (length) => {
    const charactersArray = characters.split("")
    let password = ""

    for (let i = 0; i < length; i++) {
        password += charactersArray[Math.floor(Math.random() * charactersArray.length)]
    }

    return password
}

const onGenerateButtonClicked = () => {
    const password = generatePassword(passwordLengthInput.value)

    document.getElementById("result").innerText = password;
}

generateButton.addEventListener("click", onGenerateButtonClicked)
