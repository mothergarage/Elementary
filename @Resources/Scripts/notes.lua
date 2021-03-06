path, contents = nil, ""

function Initialize()
	path = SKIN:MakePathAbsolute(SKIN:GetVariable('notesfile', SKIN:ReplaceVariables('#@#notes.txt')))
	readFromFile()
end

function Update()
	return contents
end

function writeToFile()
	local text = SELF:GetOption('temp')
	local file = io.open(path, 'w')
	assert(file, 'could not write to ' .. path)
	file:write('\239\187\191', text)
	file:close()
end

function readFromFile()
	local file = io.open(path, 'r')
	assert(file, 'could not read from ' .. path)
	contents = file:read('*a')
end