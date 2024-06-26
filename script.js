const topicNames = [
  "Sorting",
  "Greedy",
  "Maximum Subarray Sum",
  "Dynamic Programming",
  "String Matching ",
  "Backtracking",
];

let subtopic = {};

async function fetchjson(filepath) {
  try {
    let response = await fetch(filepath);

    if (!response.ok) {
      const pathPrefix = "/" + window.location.href.split("/")[3] + "/";
      response = await fetch(pathPrefix + filepath);
      if (!response.ok) {
        throw new Error("Network response was not ok");
      }
    }
    const jsonData = await response.json();
    subtopic = jsonData;
    return subtopic;
  } catch (error) {
    console.error("Error fetching json:", error);
    throw error;
  }
}

fetchjson("/subtopics.json")
  .then((data) => {
    console.log("Subtopics fetched successfully:",data);
    subtopic = data;
  })
  .catch((error) => {
    console.error("Error fetching subtopics:", error);
  });

function gendiv() {
  const container = document.querySelector(".container");

  topicNames.forEach((name) => {
    const topicDiv = document.createElement("div");
    topicDiv.className = "topic";

    const heading = document.createElement("h2");
    heading.textContent = name;
    topicDiv.appendChild(heading);

    const dropdownBtn = document.createElement("button");
    dropdownBtn.className = "dropdown-btn";
    topicDiv.appendChild(dropdownBtn);

    container.appendChild(topicDiv);
  });
}

function loadfile(path) {
  return fetch(path)
    .then((response) => response.text())
    .catch((error) => console.log(error));
}

function filepath(topic) {
  const map = {
    Sorting: "/SORT",
    Greedy: "./GREEDY",
    "Maximum Subarray Sum": "/MSS",
    "Dynamic Programming": "/DP",
    "String Matching ": "/SM",
    Backtracking: "/BT",
  };
  const ret = {};
  for (let i = 0; i < subtopic[topic].length; i++) {
    ret[subtopic[topic][i]] = `./CODES/${map[topic]}/${subtopic[topic][i]}`;
  }
  return ret;
}

document.addEventListener("DOMContentLoaded", () => {
  gendiv();
  const dropdownButtons = document.querySelectorAll(".dropdown-btn");
  dropdownButtons.forEach((btn) => {
    btn.addEventListener("click", (e) => {
      e.stopPropagation(); // Prevent event propagation
      btn.classList.toggle("active");
      const topicDiv = btn.parentElement;
      if (btn.classList.contains("active")) {
        const topic = topicDiv.querySelector("h2").textContent;
        const files = filepath(topic);

        for (const key in files) {
          const sidehead = document.createElement("h3");
          sidehead.textContent = key;
          topicDiv.appendChild(sidehead);

          const editorContainer = document.createElement("div");
          editorContainer.className = "editor-container";
          topicDiv.appendChild(editorContainer);
          const editor = ace.edit(editorContainer);
          editor.setOptions({
            wrap: true,
            wrapLimit: "80",
            theme: "ace/theme/monokai",
            mode: "ace/mode/c_cpp",
          });
          editor.setValue("Loading...");

          loadfile(files[key]).then((data) => {
            editor.setValue(data);
            editor.setReadOnly(true);
          });
        }
      } else {
        const editorContainers = topicDiv.querySelectorAll(".editor-container");
        const sideheads = topicDiv.querySelectorAll("h3");
        editorContainers.forEach((container) => container.remove());
        sideheads.forEach((head) => head.remove());
      }
    });
  });

  //check
  // Add click event listener to the document
  document.addEventListener("click", (e) => {
    const dropdownButtons = document.querySelectorAll(".dropdown-btn");
    dropdownButtons.forEach((btn) => {
      const topicDiv = btn.parentElement;
      const target = e.target;
      if (!topicDiv.contains(target)) {
        btn.classList.remove("active");
        const editorContainers = topicDiv.querySelectorAll(".editor-container");
        const sideheads = topicDiv.querySelectorAll("h3");
        editorContainers.forEach((container) => container.remove());
        sideheads.forEach((head) => head.remove());
      }
    });
  });
});
