let encodeButton = document.getElementById("encode")
let messageInput = document.getElementById("message")

const onEncodeButtonClicked = () => {
    document.getElementById("result").innerText = btoa(messageInput.value)
}

encodeButton.addEventListener("click", onEncodeButtonClicked)